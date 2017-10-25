// http://www.lintcode.com/zh-cn/problem/matrix-ret-traversal
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
   * @param matrix: a matrix of integers
   * @return: a vector of integers

  */
  vector<int> printZMatrix(vector<vector<int>> &matrix) {
    const int m = matrix.size();
    const int n = matrix[0].size();
    vector<int> ret;

    if (matrix.empty())
      return ret;

    for (int k = 0; k < m + n - 1; k++) {
      if (k % 2) {
        for (int j = std::min(k, n - 1); j >= std::max(0, k - m + 1); j--) {
          ret.push_back(matrix[k - j][j]);
        }
      } else {
        // move row idx if diagonal idx is even
        for (int i = std::min(k, m - 1); i >= std::max(0, k - n + 1); i--) {
          ret.push_back(matrix[i][k - i]);
        }
      }
    }
    return ret;
  }
};

int main() {
  vector<vector<int>> test{vector<int>{1, 2}};
  Solution so;
  auto ret = so.printZMatrix(test);
  for (auto i : ret)
    cout << i << endl;
  return 0;
}
