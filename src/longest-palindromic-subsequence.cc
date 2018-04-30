// http://www.lintcode.com/zh-cn/problem/longest-palindromic-subsequence
#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param s: the maximum length of s is 1000
   * @return: the longest palindromic subsequence's length
   */
  int longestPalindromeSubseq(string &s) {
    if (s.empty())
      return 0;
    const int n = s.size();


    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = n - 1; i >= 0; --i) {
      dp[i][i] = 1;
      for (int j = i + 1; j < n; ++j) {
        // 相等则长度在原来基础上增加2
        if (s[i] == s[j]) {
          dp[i][j] = dp[i + 1][j - 1] + 2;
        } else {                // 否则就看拿掉其中一个字符的情况，取最大的
          dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);
        }
      }
    }

    return dp[0][n - 1];
  }
};
