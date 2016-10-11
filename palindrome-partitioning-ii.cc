// http://www.lintcode.com/zh-cn/problem/palindrome-partitioning-ii
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param s a string
   * @return an integer
   按照分割回文串去实现，找出最小的分割次数超时。
   改为用动态规划去实现。设置一个数组2boolean维数组isPd[  ][  ]
   isPd[ i ][ j ] = true 表示字符串s[ i , j ]是回文串，isPd[ i ][ j ]  = false 表示字符串s[ i ][ j ]不是回文串。也用动态规划去生成

   再用dp[i] 表示0..i之间的最小分割数
  */
  int minCut(string s) {
    if (s.empty())
      return 0;

    const int n = s.size();
    // dp1[i][j] is true, means s[i, j] is palindrome
    vector<vector<bool>> dp1(n, vector<bool>(n, false));
    // calculation dp1
    for (int len = 1; len <= n; len++) {
      for (int i = 0; i + len - 1 < n; i++) {
        int j = i + len - 1;
        if (len == 1) {
          dp1[i][j] = true;
        } else if (s[i] == s[j] && (i == j - 1 || dp1[i + 1][j - 1])) {
          dp1[i][j] = true;
        }
      }
    }

    // dp2[i] means 0..i minimum cut
    vector<int> dp2(n, std::numeric_limits<int>::max());
    for (int i = 0; i < n; i++) {
      // no need to cut, it already is
      if (dp1[0][i]) {
        dp2[i] = 0;
        continue;
      }

      for (int j = 0; j < i; j++) {
        // 如果s(j + 1, i) 是回文, 则从J这里多切一刀和之前的比较,看哪个最小
        if (dp1[j + 1][i])
          dp2[i] = std::min(dp2[i], dp2[j] + 1);
      }
    }

    return dp2[n - 1];
  }
};

int main()
{
  Solution so;
  auto ret = so.minCut("ab");
  cout << ret << endl;
  return 0;
}
