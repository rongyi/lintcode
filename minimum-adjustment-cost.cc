// http://www.lintcode.com/zh-cn/problem/minimum-adjustment-cost
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
   * @param A: An integer array.
   * @param target: An integer.

   * http://www.geeksforgeeks.org/find-minimum-adjustment-cost-of-an-array/
   * In order to minimize the adjustment cost ∑|A[i] – Anew[i]| for all index i in the array, |A[i] – Anew[i]| should be as close to zero as possible. Also, |A[i] – Anew[i+1] ]| <= Target.
   * This problem can be solved by dynamic programming.
   * Let dp[i][j] defines minimal adjustment cost on changing A[i] to j, then the DP relation is defined by –
   * dp[i][j] = min{dp[i - 1][k]} + |j - A[i]|
   *         for all k's such that |k - j| <= target
   * Here, 0 <= i < n and 0 <= j <= M where n is number of elements in the array and M = 100. We have to consider all k such that max(j – target, 0) <= k <= min(M, j + target)
   * Finally, the minimum adjustment cost of the array will be min{dp[n – 1][j]} for all 0 <= j <= M.
   */
  int MinAdjustmentCost(vector<int> A, int target) {
    const int n = A.size();
    int dp[n][100 + 1];
    // initial case
    for (int j = 0; j <= 100; j++) {
      dp[0][j] = std::abs(j - A[0]);
    }
    for (int i = 1; i < n; i++) {
      for (int j = 0; j <= 100; j++) {
        dp[i][j] = std::numeric_limits<int>::max();
        for (int k = std::max(j - target, 0); k <= std::min(100, j + target); k++) {
          dp[i][j] = std::min(dp[i][j], dp[i - 1][k] + std::abs(A[i] - j));
        }
      }
    }

    int ret = std::numeric_limits<int>::max();
    for (int j = 0; j <= 100; j++) {
      ret = std::min(ret, dp[n - 1][j]);
    }

    return ret;
  }
};
