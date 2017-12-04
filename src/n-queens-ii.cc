// http://www.lintcode.com/zh-cn/problem/n-queens-ii
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * Calculate the total number of distinct N-Queen solutions.
   * @param n: The number of queens.
   * @return: The total number of distinct solutions.
   */
  int totalNQueens(int n) {
    columns_ = vector<int>(n, 0);

    int ret = 0;

    // indicate the column index of each row
    vector<int> queen_col_vec(n, 0);
    dfs(ret, queen_col_vec, 0);

    return ret;
  }

private:
  void dfs(int &ret, vector<int> &queen_col_vec, int row) {
    const int N = queen_col_vec.size();
    if (row == N) {
      ret++;
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
    }
  }

private:
  vector<int> columns_;
  std::unordered_map<int, int> main_diag_;
  std::unordered_map<int, int> anti_diag_;
};
