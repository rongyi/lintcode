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
