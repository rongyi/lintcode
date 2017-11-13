// http://www.lintcode.com/zh-cn/problem/number-of-big-islands
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;
class Solution {
public:
  /*
   * @param : a 2d boolean array
   * @param : an integer
   * @return: the number of Islands
   */
  int numsofIsland(vector<vector<bool>> grid, int k) {
    if (grid.empty() || grid[0].empty()) {
      return 0;
    }
    const int m = grid.size();
    const int n = grid[0].size();
    int count = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j]) {
          // 清除其相邻的岛屿
          int island_size = 0;
          search(grid, i, j, island_size);
          if (island_size >= k) {
            count++;
          }
        }
      }
    }
    return count;
  }

private:
  void search(vector<vector<bool>> &grid, int i, int j, int &island_size) {
    const int m = grid.size();
    const int n = grid[0].size();
    if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == false)
      return;
    grid[i][j] = false;
    ++island_size;
    search(grid, i - 1, j, island_size); // top
    search(grid, i + 1, j, island_size); // down
    search(grid, i, j - 1, island_size); // left
    search(grid, i, j + 1, island_size); // right
  }
};
