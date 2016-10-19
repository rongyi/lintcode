// http://www.lintcode.com/zh-cn/problem/maximal-rectangle
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using std::vector;
using std::cout;
using std::endl;
using std::string;


class Solution {
public:
  int maximalRectangle(vector<vector<bool>> &matrix) {
    if (matrix.empty())
      return 0;
    const int m = matrix.size();
    const int n = matrix[0].size();
    // plus 1 for n is for stack pop action, i.e. the dummy zero
    vector<vector<int>> heights(m, vector<int>(n + 1, 0));

    int ret = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j]) {
          heights[i][j] = (i == 0) ? 1 : heights[i - 1][j] + 1;
        } else {
          heights[i][j] = 0;
        }
      }
    }
    for (int i = 0; i < m; i++) {
      int area = maxAreaInHist(heights[i]);
      ret = std::max(ret, area);
    }

    return ret;
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

  // stack中总是保持递增的元素的索引，然后当遇到较小的元素后，依次出栈并计算栈中bar能围成的面积，直到栈中元素小于当前元素。
  // 塞入的最后一个0高度即是为了出栈使用
  int maxAreaInHist(vector<int> heights) {
    std::stack<int> s;
    int i = 0;
    int ret = 0;
    while (i < heights.size()) {
      if (s.empty() || heights[s.top()] <= heights[i]) {
        s.push(i++);
      } else {
        int t = s.top();
        s.pop();
        ret = std::max(ret, heights[t] * (s.empty() ? i : i - s.top() - 1));
      }
    }

    return ret;
  }
};
