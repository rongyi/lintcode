// http://www.lintcode.com/zh-cn/problem/trapping-rain-water-ii
#include <iostream>
#include <limits>
#include <queue>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param heights: a matrix of integers
   * @return: an integer
   */
  int trapRainWater(vector<vector<int>> &heights) {
    if (heights.empty())
      return 0;
    int ret = 0;
    const int m = heights.size();
    const int n = heights[0].size();
    int mx = std::numeric_limits<int>::min();

    std::priority_queue<std::pair<int, int>, vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        q;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    vector<vector<int>> dir{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
          q.push({heights[i][j], i * n + j});
          visited[i][j] = true;
        }
      }
    }

    while (!q.empty()) {
      auto t = q.top();
      q.pop();
      int h = t.first;
      int r = t.second / n;
      int c = t.second % n;
      mx = std::max(mx, h);
      for (int i = 0; i < dir.size(); ++i) {
        int x = r + dir[i][0], y = c + dir[i][1];
        if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y])
          continue;
        visited[x][y] = true;
        if (heights[x][y] < mx)
          ret += mx - heights[x][y];
        q.push({heights[x][y], x * n + y});
      }
    }
    return ret;
  }
};
