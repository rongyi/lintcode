// http://www.lintcode.com/zh-cn/problem/unique-paths
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
  /**
   * @param n, m: positive integer (1 <= n ,m <= 100)
   * @return an integer
   */
  int uniquePaths(int m, int n) {
    vector<int> dp(n, 1);
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        dp[j] += dp[j - 1];
      }
    }

    return dp[n - 1];
  }
};
