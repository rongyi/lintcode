// http://www.lintcode.com/zh-cn/problem/set-matrix-zeroes

#include <vector>
using std::vector;

class Solution {
public:
  /**
   * @param matrix: A list of lists of integers
   * @return: Void
   */
  void setZeroes(vector<vector<int>> &matrix) {
    const size_t m = matrix.size();
    if (m == 0)
      return;
    const size_t n = matrix[0].size();

    vector<bool> row(m, false);
    vector<bool> col(n, false);
    for (size_t i = 0; i < m; i++) {
      for (size_t j = 0; j < n; j++) {
        if (matrix[i][j] == 0)
          row[i] = col[j] = true;
      }
    }

    for (size_t i = 0; i < m; ++i) {
      if (row[i])
        std::fill(&matrix[i][0], &matrix[i][0] + n, 0);
    }
    for (size_t j = 0; j < n; ++j) {
      if (col[j]) {
        for (size_t i = 0; i < m; ++i) {
          matrix[i][j] = 0;
        }
      }
    }
  }
};
