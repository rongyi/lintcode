// http://www.lintcode.com/zh-cn/problem/unique-paths-ii
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
  /**
   * @param obstacleGrid: A list of lists of integers
   * @return: An integer
   */
  int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    const int m = obstacleGrid.size();
    const int n = obstacleGrid[0].size();
    vector<vector<int>> path(m + 1, vector<int>(n + 1, 0));

    if (!obstacleGrid[0][0])
      path[1][1] = 1;
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (path[i - 1][j] && !obstacleGrid[i - 1][j - 1])
          path[i][j] += path[i - 1][j];
        if (path[i][j - 1] && !obstacleGrid[i - 1][j - 1])
          path[i][j] += path[i][j - 1];
      }
    }
    return path[m][n];
  }
};
