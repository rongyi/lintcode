// http://www.lintcode.com/zh-cn/problem/spiral-matrix
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
   * @param matrix a matrix of m x n elements
   * @return an integer array
   */
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ret;
    if (matrix.empty())
      return ret;
    int m = matrix.size();
    int n = matrix[0].size();

    int visited_rows = 0;
    int visited_cols = 0;
    int x[4] = {1, 0, -1, 0};
    int y[4] = {0, 1, 0, -1};

    int direct = 0;

    int startx = 0;
    int starty = 0;

    // little trick: intial direction is goto right
    int candidate_num = n;
    int step = 0;

    while (true) {
      if (candidate_num <= 0)
        break;
      ret.push_back(matrix[startx][starty]);
      step++;
      if (step == candidate_num) {
        step = 0;
        visited_rows += x[direct] == 0 ? 0 : 1;
        visited_cols += y[direct] == 0 ? 0 : 1;

        direct++;
        direct = direct % 4;

        // only check candidate_num when direction changed
        if (x[direct] == 0) {
          candidate_num = m - visited_rows;
        } else {
          candidate_num = n - visited_cols;
        }
      }

      startx += y[direct];
      starty += x[direct];
    }

    return ret;
  }
};

int main()
{
  Solution so;
  vector<vector<int>> input{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  auto ret = so.spiralOrder(input);
  for (auto i : ret) {
    cout << i << endl;
  }

  return 0;
}
