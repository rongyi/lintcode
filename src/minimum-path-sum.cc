// http://www.lintcode.com/zh-cn/problem/minimum-path-sum
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
   * @param grid: a list of lists of integers.
   * @return: An integer, minimizes the sum of all numbers along its path
   */
  int minPathSum(vector<vector<int>> &grid) {
    if (grid.empty())
      return 0;
    const int m = grid.size();
    const int n = grid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, 0));
    // initial stat
    dp[0][0] = grid[0][0];

    for (int i = 1; i < n; i++) {
      dp[0][i] = dp[0][i - 1] + grid[0][i];
    }

    for (int i = 1; i < m; i++) {
      dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        dp[i][j] =
            std::min(dp[i - 1][j] + grid[i][j], dp[i][j - 1] + grid[i][j]);
      }
    }

    return dp[m - 1][n - 1];
  }
};
int main() {
  Solution so;
  vector<vector<int>> test{{1, 2}, {1, 1}};
  auto ret = so.minPathSum(test);
  cout << ret << endl;
  return 0;
}
