// http://www.lintcode.com/zh-cn/problem/word-search
#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param board: A list of lists of character
   * @param word: A string
   * @return: A boolean
   */
  bool exist(vector<vector<char> > &board, string word) {
    if (board.empty())
      return false;
    if (word.empty())
      return true;
    const int m = board.size();
    const int n = board[0].size();

    vector<vector<bool>> visited(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (search(word, 0, board, i, j, visited))
          return true;
      }
    }
    return false;

  }
  bool search(const string &word,
              int index,
              const vector<vector<char>> &board,
              int i, int j,
              vector<vector<bool>> &visited) {
    // boudary check
    if (i < 0 || j < 0 ||
        i == board.size() || j == board[0].size() ||
        visited[i][j] == true) {
      return false;
    }

    // mark
    visited[i][j] = true;
    bool ret = false;
    if (board[i][j] == word.at(index)) {
      if (index == word.size() - 1)
        return true;
      ret = search(word, index + 1, board, i - 1, j, visited) || // up
        search(word, index + 1, board, i + 1, j, visited) ||     // down
        search(word, index + 1, board, i, j - 1, visited) ||     // left
        search(word, index + 1, board, i, j + 1, visited);       // right
    }

    // mark back
    visited[i][j] = false;

    return ret;
  }
};

int main()
{
  Solution so;
  vector<char> row1{'A', 'B', 'C', 'E'};
  vector<char> row2{'S', 'F', 'C', 'S'};
  vector<char> row3{'A', 'D', 'E', 'E'};
  vector<vector<char>> test{row1, row2, row3};

  auto ret = so.exist(test, "SEE");
  cout << ret << endl;

  return 0;
}
