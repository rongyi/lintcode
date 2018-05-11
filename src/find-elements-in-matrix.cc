// http://www.lintcode.com/zh-cn/problem/find-elements-in-matrix
#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param Matrix: the input
   * @return: the element which appears every row
   */
  int FindElements(vector<vector<int>> &matrix) {
    const int m = matrix.size();
    const int n = matrix[0].size();
    vector<std::unordered_set<int>> aux;
    for (int i = 0; i < m - 1; i++) {
      std::unordered_set<int> cur_row;
      for (int j = 0; j < n; j++) {
        cur_row.insert(matrix[i][j]);
      }
      aux.push_back(cur_row);
    }

    for (int j = 0; j < n; j++) {
      bool all_row = true;
      for (int set_idx = 0; set_idx < aux.size(); set_idx++) {
        if (aux[set_idx].find(matrix[m - 1][j]) == aux[set_idx].end()) {
          all_row = false;
          continue;
        }
        if (set_idx == aux.size() - 1 && all_row) {
          return matrix[m - 1][j];
        }
      }
    }
    return -1;
  }
};
