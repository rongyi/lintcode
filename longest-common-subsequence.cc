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
    const int m = a.length();
    const int n = b.length();

    return doLCS(a, b, m, n);
  }

  int doLCS(const string &a, const string &b, int m, int n) {
    if (m == 0 || n == 0)
      return 0;
    if (a[m - 1] == b[n - 1])
      return 1 + doLCS(a, b, m - 1, n - 1);
    else
      return std::max(doLCS(a, b, m, n - 1), doLCS(a, b, m - 1, n));
  }
};
