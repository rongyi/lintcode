// http://www.lintcode.com/zh-cn/problem/longest-common-subsequence
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param A, B: Two strings.
   * @return: The length of longest common subsequence of A and B.
   */
  int longestCommonSubsequence(string a, string b) {
    const int m = a.size();
    const int n = b.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m + 1; i++) {
      for (int j = 0; j < n + 1; j++) {
        if (i == 0 || j == 0) {
          dp[i][j] = 0;
        } else {
          if (a[i - 1] == b[j - 1]) {
            dp[i][j] = dp[i - 1][j - 1] + 1;
          } else {
            dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
          }
        }
      }
    }

    return dp[m][n];
  }

  /*
    Let the input sequences be X[0..m-1] and Y[0..n-1] of lengths m and n respectively. And let L(X[0..m-1], Y[0..n-1]) be
    the length of LCS of the two sequences X and Y. Following is the recursive definition of L(X[0..m-1], Y[0..n-1]).
    If last characters of both sequences match (or X[m-1] == Y[n-1]) then
    L(X[0..m-1], Y[0..n-1]) = 1 + L(X[0..m-2], Y[0..n-2])

    If last characters of both sequences do not match (or X[m-1] != Y[n-1]) then
    L(X[0..m-1], Y[0..n-1]) = MAX ( L(X[0..m-2], Y[0..n-1]), L(X[0..m-1], Y[0..n-2])
   */
  int doLCS(const string &a, const string &b, int m, int n) {
    if (m == 0 || n == 0)
      return 0;
    if (a[m - 1] == b[n - 1])
      return 1 + doLCS(a, b, m - 1, n - 1);
    else
      return std::max(doLCS(a, b, m, n - 1), doLCS(a, b, m - 1, n));
  }
};
