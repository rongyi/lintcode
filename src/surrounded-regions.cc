// http://www.lintcode.com/zh-cn/problem/surrounded-regions
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::queue;

class Solution {
public:
  static const char kReplace = 'R';
  /**
   * @param board a 2D board containing 'X' and 'O'
   * @return void
   */
  void surroundedRegions(vector<vector<char>> &board) {
    if (board.empty())
      return;
    const int m = board.size();
    const int n = board[0].size();
    // 从四周切进去发现的O不能替换，所以这里有个转换，转换成其他值
    for (int i = 0; i < n; i++) {
      // top line
      bfs(board, 0, i);
      // bottom line
      bfs(board, m - 1, i);
    }
    for (int j = 1; j < m - 1; j++) {
      // left column
      bfs(board, j, 0);
      // right column
      bfs(board, j, n - 1);
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == 'O')
          board[i][j] = 'X';
        else if (board[i][j] == Solution::kReplace)
          board[i][j] = 'O';
      }
    }
  }

private:
  void bfs(vector<vector<char>> &board, int i, int j) {
    using Coordinate = std::pair<int, int>;
    std::queue<Coordinate> q;
    const int m = board.size();
    const int n = board[0].size();

    auto isValid = [&](const Coordinate &c) -> bool {
      const int x = c.first;
      const int y = c.second;

      if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'O')
        return false;

      return true;
    };

    auto nextStep = [&](const Coordinate &c) {
      vector<Coordinate> ret;
      const int x = c.first;
      const int y = c.second;
      const Coordinate fourDirection[4] = {
        {x - 1, y}/*left*/, {x + 1, y}/*right*/, {x, y - 1}/*down*/, {x, y + 1}/*up*/};
      for (int k = 0; k < 4; ++k) {
        if (isValid(fourDirection[k])) {
          board[fourDirection[k].first][fourDirection[k].second] =
              Solution::kReplace;
          ret.push_back(fourDirection[k]);
        }
      }
      return ret;
    };

    Coordinate cur = {i, j};
    if (isValid(cur)) {
      board[i][j] = Solution::kReplace;
      q.push(cur);
    }

    while (!q.empty()) {
      auto cur = q.front();
      q.pop();
      // all possible next steps
      auto next = nextStep(cur);
      for (auto n : next)
        q.push(n);
    }
  }
};
