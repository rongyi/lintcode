// http://www.lintcode.com/zh-cn/problem/n-queens
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

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
    // main_diag_ = vector<int>(2 * n, 0);
    // anti_diag_ = vector<int>(2 * n, 0);

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
        // no need to for
        cur_row[queen_col_vec[i]] = 'Q';
        // one row done
        cur_layout.push_back(cur_row);
      }

      ret.push_back(cur_layout);
      return;
    }

    for (int j = 0; j < N; ++j) {
      const bool ok = columns_[j] == 0 && main_diag_[row + j] == 0 &&
                      anti_diag_[row - j] == 0;

      if (!ok)
        continue;

      queen_col_vec[row] = j;
      columns_[j] = main_diag_[row + j] = anti_diag_[row - j] = 1;

      dfs(ret, queen_col_vec, row + 1);

      // restore
      columns_[j] = main_diag_[row + j] = anti_diag_[row - j] = 0;
      // queen_col_vec之所以不用回撤，是因为像全局变量一样每次被overwrite了
    }
  }

private:
  // 标记哪一列上放置了皇后
  vector<int> columns_;
  // 标记占据哪些主对角线
  // 在一个正斜线上有一个特征: row + col == 固定值
  std::unordered_map<int, int> main_diag_;
  // 标记占据哪些辅对角线
  // 同样在一个反斜线上有一个特征： row - col == 固定值
  std::unordered_map<int, int> anti_diag_;
};
