// http://www.lintcode.com/zh-cn/problem/number-of-islands

#include <vector>
using std::vector;

class Solution {
public:
  /**
   * @param grid a boolean 2D matrix
   * @return an integer
   */
  int numIslands(vector<vector<bool>>& grid) {
    if (grid.empty() || grid[0].empty()) {
      return 0;
    }
    const int m = grid.size();
    const int n = grid[0].size();
    int count = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j]) {
          count++;
          // 清楚其相邻的岛屿
          search(grid, i, j);
        }

      }
    }
    return count;
  }
private:
  void search(vector<vector<bool>> &grid, int i, int j) {
    const int m = grid.size();
    const int n = grid[0].size();
    if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == false)
      return;
    grid[i][j] = false;
    search(grid, i - 1, j); // top
    search(grid, i + 1, j); // down
    search(grid, i, j - 1); // left
    search(grid, i, j + 1); // right
  }
};
