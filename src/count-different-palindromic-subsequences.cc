// http://www.lintcode.com/zh-cn/problem/count-different-palindromic-subsequences
#include <cstring>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param str: a string S
   * @return: the number of different non-empty palindromic subsequences in S
   */
  int countPalindSubseqSEQ(string &str) {
    const int n = str.size();
    vector<vector<int>> ret(n + 1, vector<int>(n + 1, 0));
    return count(str, 0, str.length() - 1, ret);
  }

  // 使用一个二维的dp数组，其中dp[i][j]表示子字符串[i,
  // j]中的不同回文子序列的个数，我们初始化dp[i][i]为1，因为任意一个单个字符就是一个回文子序列，其余均为0。
  // 这里的更新顺序不是正向，也不是逆向，而是斜着更新，对于"bccb"的例子，其最终dp数组如下，我们可以看到其
  // 更新顺序分别是红-绿-蓝-橙。

  //   b c c b
  // b 1 2 3 6
  // c 0 1 2 3
  // c 0 0 1 2
  // b 0 0 0 1
  // 这样更新的好处是，更新当前位置时，其左，下，和左下位置的dp值均已存在，而当前位置的dp值需要用到这三个位置的dp值。
  // 我们观察上面的dp数组，可以发现当S[i]不等于S[j]的时候，dp[i][j]
  // = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j -  1]，即当前的dp值等于左边值加下边值减去左下值，
  // 因为算左边值的时候包括了左下的所有情况，而算下边值的时候也包括了左下值的所有情况，那么左下值就多算了一遍，
  // 所以要减去。而当S[i]等于S[j]的时候，情况就比较复杂了，需要分情况讨论，因为我们不知道中间还有几个和S[i]相等的值。
  // 举个简单的例子，比如"aba"和"aaa"，当i = 0, j = 2的时候，两个字符串均有S[i] == S[j]，此时二者都新增两个子序列"a"和"aa"，
  // 但是"aba"中间的"b"就可以加到结果res中，而"aaa"中的"a"就不能加了，因为和外层的单独"a"重复了。我们的目标就要找到中间重复的"a"。
  // 所以我们让left = i + 1, right = j - 1，然后对left进行while循环，如果left <= right,
  // 且S[left] != S[i]的时候，left向右移动一个；同理，对right进行while循环，如果left <= right, 且S[right] !=  S[i]的时候，
  // left向左移动一个。这样最终left和right值就有三种情况：

  // 1. 当left > righ时，说明中间没有和S[i]相同的字母了，就是"aba"这种情况，那么就有dp[i][j] = dp[i + 1][j - 1] * 2 + 2，
  // 其中dp[i + 1][j - 1]是中间部分的回文子序列个数，为啥要乘2呢，因为中间的所有子序列可以单独存在，也可以再外面包裹上字母a，
  // 所以是成对出现的，要乘2。加2的原因是外层的"a"和"aa"也要统计上。

  // 2. 当left = right时，说明中间只有一个和S[i]相同的字母，就是"aaa"这种情况，那么有dp[i][j] = dp[i + 1][j - 1] * 2 + 1，
  // 其中乘2的部分跟上面的原因相同，加1的原因是单个字母"a"的情况已经在中间部分算过了，外层就只能再加上个"aa"了。

  // 3. 当left < right时，说明中间至少有两个和S[i]相同的字母，就是"aabaa"这种情况，那么有dp[i][j]
  // = dp[i + 1][j - 1] * 2 - dp[left + 1][right - 1]，其中乘2的部分跟上面的原因相同，
  // 要减去left和right中间部分的子序列个数的原因是其被计算了两遍，要将多余的减掉。

  int countPalindSubseq(string &str) {
    int n = str.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
      dp[i][i] = 1;

    for (int len = 1; len <= n; ++len) {
      for (int i = 0; i < n - len; ++i) {
        const int j = i + len;
        if (str[i] == str[j]) {
          dp[i][j] = dp[i + 1][j - 1] * 2;
          int l = i + 1;
          int r = j - 1;
          while (l <= r && str[l] != str[i])
            ++l;
          while (l <= r && str[r] != str[i])
            --r;
          if (l == r)
            dp[i][j] += 1;
          else if (l > r)
            dp[i][j] += 2;
          else
            dp[i][j] -= dp[l + 1][r - 1];
        } else {
          dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
        }

        dp[i][j] = (dp[i][j] + kMod) % kMod;
      }
    }

    return dp[0][n - 1];
  }

private:
  long count(const string &S, int s, int e, vector<vector<int>> &ret) {
    if (s > e)
      return 0;
    if (s == e)
      return 1;
    if (ret[s][e] > 0)
      return ret[s][e];

    long ans = 0;
    if (S[s] == S[e]) {
      int l = s + 1;
      int r = e - 1;
      while (l <= r && S[l] != S[s])
        ++l;
      while (l <= r && S[r] != S[s])
        --r;
      if (l > r)
        ans = count(S, s + 1, e - 1, ret) * 2 + 2;
      else if (l == r)
        ans = count(S, s + 1, e - 1, ret) * 2 + 1;
      else
        ans = count(S, s + 1, e - 1, ret) * 2 - count(S, l + 1, r - 1, ret);
    } else {
      ans = count(S, s, e - 1, ret) + count(S, s + 1, e, ret) -
            count(S, s + 1, e - 1, ret);
    }

    return ret[s][e] = (ans + kMod) % kMod;
  }

private:
  static constexpr long kMod = 1000000007;
};

int main() {
  string str = "bccb";
  Solution so;
  cout << "Total palindromic subsequence are : " << so.countPalindSubseq(str)
       << endl;
  return 0;
}
