// http://www.lintcode.com/zh-cn/problem/paint-fence
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
   * @param n non-negative integer, n posts
   * @param k non-negative integer, k colors
   * @return an integer, the total number of ways
   */
  int numWays(int n, int k) {
    if (n == 0 || k == 0)
      return 0;
    vector<int> dp(n, 0);
    dp[0] = k;
    dp[1] = k * k;
    for (int i = 2; i < n; i++) {
      dp[i] = dp[i - 2] * (k - 1) + dp[i - 1] * (k - 1);
    }
    return dp[n - 1];
  }
};
