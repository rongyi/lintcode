// http://www.lintcode.com/zh-cn/problem/n-queens
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
   * Get all distinct N-Queen solutions
   * @param n: The number of queens
   * @return: All distinct solutions
   * For example, A string '...Q' shows a queen on forth position
   */
  vector<vector<string>> solveNQueens(int n) {
    columns_ = vector<int>(n, 0);
    main_diag_ = vector<int>(2 * n, 0);
    anti_diag_ = vector<int>(2 * n, 0);

    vector<vector<string>> ret;
    // indicate the column index of each row
    vector<int> queen_col_vec(n, 0);
    dfs(ret, queen_col_vec, 0);

    return ret;
  }

private:
  void dfs(vector<vector<string>> &ret, vector<int> &queen_col_vec, int row) {
    const int N = queen_col_vec.size();
    if (row == N) {
      // final layout for a solution
      vector<string> cur_layout;
      for (int i = 0; i < N; i++) {
        string cur_row(N, '.');
        for (int j = 0; j < N; j++) {
          if (j == queen_col_vec[i])
            cur_row[j] = 'Q';
        }
        // one row done
        cur_layout.push_back(cur_row);
      }

      ret.push_back(cur_layout);
      return;
    }

    for (int j = 0; j < N; ++j) {
      const bool ok = columns_[j] == 0 && main_diag_[row + j] == 0 &&
                      anti_diag_[row - j + N] == 0;

      if (!ok)
        continue;

      queen_col_vec[row] = j;
      columns_[j] = main_diag_[row + j] = anti_diag_[row - j + N] = 1;

      dfs(ret, queen_col_vec, row + 1);

      // restore
      columns_[j] = main_diag_[row + j] = anti_diag_[row - j + N] = 0;
    }
  }

private:
  vector<int> columns_;
  vector<int> main_diag_;
  vector<int> anti_diag_;
};
