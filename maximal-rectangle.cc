// http://www.lintcode.com/zh-cn/problem/maximal-rectangle
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  int maximalRectangle(vector<vector<bool>> &matrix) {
  }


  /**
   * @param matrix a boolean 2D matrix
   * @return an integer
   * brute force
  */
  int maximalRectangleTLEVersion(vector<vector<bool>> &matrix) {
    if (matrix.empty())
      return 0;
    const int m = matrix.size();
    const int n = matrix[0].size();
    int ret = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j]) {
          auto cur_max = curMax(matrix, i, j);
          ret = std::max(ret, cur_max);
        }
      }
    }

    return ret;
  }

private:
  int curMax(vector<vector<bool>> &matrix, int row, int col) {
    int ret = 0;
    int min_width = std::numeric_limits<int>::max();

    for (int i = row; i < matrix.size() && matrix[i][col]; i++) {
      int cur_width = 0;
      while (col + cur_width < matrix[row].size() &&
             matrix[i][col + cur_width]) {
        cur_width++;
      }
      // 选最短的长度可以保证当前为一个矩形, 例子就是如果后面遇到一个很长的
      // 1, 则这行的判断仍然要以之前遇到的最短的那个宽度为准.
      min_width = std::min(min_width, cur_width);

      int cur_area = min_width * (i - row + 1);
      ret = std::max(cur_area, ret);
    }

    return ret;
  }
};
