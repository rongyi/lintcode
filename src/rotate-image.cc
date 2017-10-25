// http://www.lintcode.com/zh-cn/problem/rotate-image

class Solution {
public:
  /**
   * @param matrix: A list of lists of integers
   * @return: Void
   */
  void rotate(vector<vector<int>> &matrix) {
    const int size = matrix.size();
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size - i; j++) {
        int tmp = matrix[i][j];
        matrix[i][j] = matrix[size - j - 1][size - i - 1];
        matrix[size - j - 1][size - i - 1] = tmp;
      }
    }
    for (int i = 0; i < size / 2; i++) {
      for (int j = 0; j < size; j++) {
        int tmp = matrix[i][j];
        matrix[i][j] = matrix[size - i - 1][j];
        matrix[size - i - 1][j] = tmp;
      }
    }
  }
};
