// http://www.lintcode.com/zh-cn/problem/ones-and-zeroes
#include <vector>
#include <iostream>
#include <string>
#include <bitset>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param strs: an array with strings include only 0 and 1
   * @param m: An integer
   * @param n: An integer
   * @return: find the maximum number of strings
   */
  int findMaxForm(vector<string> &strs, int m, int n) {
    vector<vector<int>> dp(m+1, vector<int>(n + 1, 0));
    for (string str : strs) {
      int zero = 0;
      int one = 0;
      for (char c : str) {
        if (c == '0' ) {
          zero++;
        } else {
          one++;
        }
      }

      for (int i = m; i >= zero; --i) {
        for (int j = n; j >= one; --j) {
          dp[i][j] = std::max(dp[i][j], dp[i - zero][j - one] + 1);
        }
      }
    }
    return dp[m][n];
  }
};
