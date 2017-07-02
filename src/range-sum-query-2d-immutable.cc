// http://www.lintcode.com/zh-cn/problem/range-sum-query-2d-immutable
#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class NumMatrix {
public:
  NumMatrix(vector<vector<int>> matrix) {
    if (matrix.empty() || matrix[0].empty())
      return;
    dp_.resize(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));

    for (int i = 1; i <= matrix.size(); ++i) {
      for (int j = 1; j<= matrix[0].size(); ++j) {
        dp_[i][j] = dp_[i][j - 1] + dp_[i - 1][j] - dp_[i - 1][j - 1] + matrix[i - 1][j - 1];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return  dp_[row2 + 1][col2 + 1] - dp_[row1][col2 + 1] - dp_[row2 + 1][col1] + dp_[row1][col1];
  }
private:
  vector<vector<int>> dp_;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
