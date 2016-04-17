// http://www.lintcode.com/zh-cn/problem/valid-sudoku

#include <vector>
using std::vector;

class Solution {
public:
  /**
   * @param board: the board
   * @return: wether the Sudoku is valid
   */
  bool isValidSudoku(const vector<vector<char> >& board) {
    bool used[9];

    for (int i = 0; i < 9; i++) {
      std::fill(used, used + 9, false);
      for (int j = 0; j < 9; ++j) {
        if (!check(board[i][j], used))
          return false;
      }
      std::fill(used, used + 9, false);
      for (int j = 0; j < 9; ++j) {
        if (!check(board[j][i], used))
          return false;
      }
    }
    for (int r = 0; r < 3; r++) {
      for (int c = 0; c < 3; c++) {
        std::fill(used, used + 9, false);
        for (int i = r * 3; i < r * 3 + 3; ++i) {
          for (int j = c * 3; j < c * 3 + 3; ++j) {
            if (!check(board[i][j], used))
              return false;
          }
        }
      }
    }
    return true;
  }

private:
  bool check(char ch, bool used[9]) {
    if (ch == '.')
      return true;
    if (used[ch - '1']) // 出现第二次了
      return false;
    return used[ch - '1'] = true; //记录，并返回OK
  }
};
