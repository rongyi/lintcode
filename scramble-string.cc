// http://www.lintcode.com/zh-cn/problem/scramble-string
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
   * @param s1 A string
   * @param s2 Another string
   * @return whether s2 is a scrambled string of s1
   */
  bool isScrambleRecursiveVersion(string& s1, string& s2) {
    if (s1.size() != s2.size())
      return false;

    if (s1 == s2)
      return true;

    auto s1cp = s1;
    auto s2cp = s2;
    std::sort(s1cp.begin(), s1cp.end());
    std::sort(s2cp.begin(), s2cp.end());
    if (s1cp != s2cp)
      return false;

    for (int i = 1; i < s1.size(); i++) {
      auto s1sub1 = s1.substr(0, i);
      auto s2sub1 = s2.substr(0, i);
      auto s1sub2 = s1.substr(i);
      auto s2sub2 = s2.substr(i);

      if (isScramble(s1sub1, s2sub1) &&
          isScramble(s1sub2, s2sub2))
        return true;
      auto s2sub3 = s2.substr(s2.size() - i);
      auto s2sub4 = s2.substr(0, s2.size() - i);
      if (isScramble(s1sub1, s2sub3) &&
          isScramble(s1sub2, s2sub4))
        return true;
    }

    return false;
  }

  /*
    动态规划用数组来保存子问题，设dp[k][i][j]表示s2从j开始长度为k的子串是否可以由s1从i开始长度为k的子串转换而成，那么动态规划方程如下

    初始条件：dp[1][i][j] = (s1[i] == s2[j] ? true : false)

    dp[k][i][j] = ( dp[div][i][j] && dp[k-div][i+div][j+div] )  ||
    ( dp[div][i][j+k-div] && dp[k-div][i+div][j] ) (div = 1,2,3...k-1, 它表示子串分割点到子串起始端的距离)
  */
  bool isScramble(string& s1, string& s2) {
    if (s1.size() != s2.size())
      return false;

    if (s1.empty())
      return true;

    const int m = s1.size();
    vector<vector<vector<bool>>> dp(m + 1, vector<vector<bool>>(m, vector<bool>(m, false)));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < m; j++) {
        dp[1][i][j] = s1[i] == s2[j] ? true : false;
      }
    }

    for (int k = 2; k <= m; k++) {
      for (int i = 0; i <= m - k; i++) {
        for (int j = 0; j <= m - k; j++) {
          for (int div = 1; div < k && !dp[k][i][j]; div++) {
            dp[k][i][j] = (dp[div][i][j] && dp[k-div][i+div][j+div])
              || (dp[div][i][j+k-div] && dp[k-div][i+div][j]);
          }
        }
      }
    }

    return dp[m][0][0];
  }
};

int main()
{
  Solution so;
  string a("a");
  string b("a");
  auto ret = so.isScramble(a, b);
  cout << ret << endl;
  return 0;
}
