// http://www.lintcode.com/zh-cn/problem/search-a-2d-matrix-ii
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
   * @param matrix: A list of lists of integers
   * @param target: An integer you want to search in matrix
   * @return: An integer indicate the total occurrence of target in the given matrix
   */
  int searchMatrix(vector<vector<int>> &matrix, int target) {
    if (matrix.empty())
      return 0;
    const int m = matrix.size();
    const int n = matrix[0].size();

    int ret = 0;
    for (int i = m - 1, j = 0; i >= 0 && j < n;) {
      if (matrix[i][j] == target) {
        ret++;
      }

      if (matrix[i][j] < target) {
        ++j;
      } else {
        --i;
      }
    }
    return ret;
  }
};
