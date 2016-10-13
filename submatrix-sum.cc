// http://www.lintcode.com/zh-cn/problem/submatrix-sum
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;

class Solution {
public:
  /**
   * @param matrix an integer matrix
   * @return the coordinate of the left-up and right-down number
   */
  vector<vector<int>> submatrixSum(vector<vector<int>>& matrix) {
    vector<vector<int>> ret;
    if (matrix.empty() || matrix[0].empty())
      return ret;
    const int m = matrix.size();
    const int n = matrix[0].size();
    for (int i = 0; i < n; i++) {
      vector<int> sum(m);
      for (int j = i; j < n; j++) {
        for (int k = 0; k < m; k++) {
          sum[k] += matrix[k][j];
        }
        int last_sum = 0;
        unordered_map<int, int> aux;
        aux.insert(std::make_pair(0, -1));

        for (int v = 0; v < m; v++) {
          last_sum += sum[v];
          if (aux.find(last_sum) != aux.end()) {
            ret.push_back({aux[last_sum] + 1, i});
            ret.push_back({v, j});
            return ret;
          }
          aux.insert(std::make_pair(last_sum, v));
        }
      }
    }

    return ret;
  }
};

int main()
{
  Solution so;
  vector<vector<int>> input{{1, 5, 7}, {3, 7, -8}, {4, -8, 9}};
  auto ret = so.submatrixSum(input);
  cout << ret.size() << endl;
  return 0;
}
