// http://www.lintcode.com/zh-cn/problem/paint-fence
#include <iostream>
#include <string>
#include <vector>

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
    // 1.
    // 如果第3个柱子的颜色跟第2个一样，那么他必须跟第一个柱子不一样，所以，前3个柱子的染色方案有k
    // * (k - 1)种
    // 2.
    // 如果第3个柱子的颜色跟第2个不一样，那么他跟第一个柱子没关系了，所以，前3个柱子的染色方案有k
    // * k * (k - 1)种
    vector<int> dp(n, 0);
    dp[0] = k;
    dp[1] = k * k;

    for (int i = 2; i < n; i++) {
      dp[i] = dp[i - 2] * (k - 1) + dp[i - 1] * (k - 1);
    }
    return dp[n - 1];
  }
};
