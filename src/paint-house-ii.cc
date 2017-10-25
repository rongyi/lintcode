// http://www.lintcode.com/zh-cn/problem/paint-house-ii
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param costs n x k cost matrix
   * @return an integer, the minimum cost to paint all houses
   # this version will time exceed!!
   */
  int minCostIITimeoutVersion(vector<vector<int>> &costs) {
    const int m = costs.size();
    if (m == 0)
      return 0;
    const int n = costs[0].size();
    // in case overflow
    vector<vector<long long>> ret(m, vector<long long>(n, 0));

    // the first row is its value itself
    for (int i = 0; i < n; i++) {
      ret[0][i] = costs[0][i];
    }

    for (int i = 1; i < m; i++) {
      for (int j = 0; j < n; j++) {
        long long min = std::numeric_limits<long long>::max();
        for (int k = 0; k < n; k++) {
          // ignore the same color
          if (k == j)
            continue;
          if (ret[i - 1][k] < min)
            min = ret[i - 1][k];
        }
        ret[i][j] = min + costs[i][j];
      }
    }

    // now select the minimum
    long long value = std::numeric_limits<long long>::max();
    for (auto i : ret[m - 1]) {
      if (i < value)
        value = i;
    }

    return value;
  }
  int minCostII(vector<vector<int>> &costs) {
    if (costs.empty() || costs[0].empty())
      return 0;
    vector<vector<int>> dp = costs;
    int min_top1 = -1;
    int min_top2 = -1;
    for (int i = 0; i < dp.size(); i++) {
      int last_min1 = min_top1;
      int last_min2 = min_top2;
      min_top1 = -1;
      min_top2 = -1;
      for (int j = 0; j < dp[i].size(); j++) {
        if (j != last_min1) {
          dp[i][j] += last_min1 < 0 ? 0 : dp[i - 1][last_min1];
        } else {
          dp[i][j] += last_min2 < 0 ? 0 : dp[i - 1][last_min2];
        }
        if (min_top1 < 0 || dp[i][j] < dp[i][min_top1]) {
          min_top2 = min_top1;
          min_top1 = j;
        } else if (min_top2 < 0 || dp[i][j] < dp[i][min_top2]) {
          min_top2 = j;
        }
      }
    }

    return dp.back()[min_top1];
  }
};
