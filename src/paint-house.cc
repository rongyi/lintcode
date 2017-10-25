// http://www.lintcode.com/zh-cn/problem/paint-house
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
   * @param costs n x 3 cost matrix
   * @return an integer, the minimum cost to paint all houses
   */
  int minCost(vector<vector<int>> &costs) {
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
        ret[i][j] = std::min(ret[i - 1][(j + 1) % 3], ret[i - 1][(j + 2) % 3]) +
                    costs[i][j];
      }
    }

    return std::min(std::min(ret[m - 1][0], ret[m - 1][1]), ret[m - 1][2]);
  }
};
