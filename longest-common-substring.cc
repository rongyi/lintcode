// http://www.lintcode.com/zh-cn/problem/longest-common-substring
#include <vector>
#include <iostream>
#include <string>
#include <cstring>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param A, B: Two string.
   * @return: the length of the longest common substring.
   */
  int longestCommonSubstring(string &a, string &b) {
    if (a.empty() || b.empty())
      return 0;
    const int m = a.size();
    const int n = b.size();

    int lcs[m + 1][n + 1];
    std::memset(lcs, 0, sizeof(lcs));
    int ret = 0;

    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (a[i - 1] == b[j - 1])
            lcs[i][j] = lcs[i - 1][j - 1] + 1;
        if (lcs[i][j] > ret)
          ret = lcs[i][j];
      }
    }
    return ret;
  }
};
