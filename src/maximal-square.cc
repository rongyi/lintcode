// http://www.lintcode.com/zh-cn/problem/maximal-square
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
   * @param matrix: a matrix of 0 and 1
   * @return: an integer
   dp: state[x][y] = 1 + min{state[x-1][y], state[x][y-1], state[x-1][y-1]}
   */
  int maxSquare(vector<vector<int>> &matrix) {
    if (matrix.empty())
      return 0;
    const int m = matrix.size();
    const int n = matrix[0].size();
    vector<vector<int>> state(m, vector<int>(n, 0));

    int ret = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == 1) {
          state[i][j] = 1;
          ret = 1;
        }
      }
    }
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (state[i][j] != 0) {
          state[i][j] =
              1 + std::min(state[i - 1][j],
                           std::min(state[i - 1][j - 1], state[i][j - 1]));
          if (state[i][j] > ret)
            ret = state[i][j];
        }
      }
    }

    return ret * ret;
  }
};
