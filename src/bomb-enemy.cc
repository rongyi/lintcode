// http://www.lintcode.com/zh-cn/problem/bomb-enemy
#include <vector>
#include <iostream>
#include <string>
#include <bitset>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param grid: Given a 2D grid, each cell is either 'W', 'E' or '0'
   * @return: an integer, the maximum enemies you can kill using one bomb
   */
  int maxKilledEnemies(vector<vector<char>> &grid) {
    if (grid.empty()) {
      return 0;
    }
    const int m = grid.size();
    const int n = grid[0].size();

    vector<vector<int>> v1(m, vector<int>(n, 0));
    auto v2 = v1;
    auto v3 = v1;
    auto v4 = v1;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int kill = (j == 0 || grid[i][j] == 'W') ? 0 : v1[i][j - 1];
        v1[i][j] = grid[i][j] == 'E' ? kill + 1 : kill;
      }

      for (int j = n - 1; j >= 0; --j) {
        int kill = (j == n - 1 || grid[i][j] == 'W') ? 0 : v2[i][j + 1];
        v2[i][j] = grid[i][j] == 'E' ? kill + 1 : kill;
      }
    }

    for (int j = 0; j < n; ++j) {
      for (int i = 0; i < m; ++i) {
        int kill = (i == 0 || grid[i][j] == 'W') ? 0 : v3[i - 1][j];
        v3[i][j] = grid[i][j] == 'E' ? kill + 1 : kill;
      }

      for (int i = m - 1; i >= 0; --i) {
        int kill = (i == m - 1 || grid[i][j] == 'W') ? 0 : v4[i+1][j];
        v4[i][j] = grid[i][j] == 'E' ? kill + 1 : kill;
      }
    }


    int ret = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '0') {
          ret = std::max(ret, v1[i][j] + v2[i][j] + v3[i][j] + v4[i][j]);
        }
      }
    }

    return ret;
  }
};
