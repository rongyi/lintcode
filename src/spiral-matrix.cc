// http://www.lintcode.com/zh-cn/problem/spiral-matrix
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Solution {
public:
  /**
   * @param matrix a matrix of m x n elements
   * @return an integer array
   */
  vector<int> spiralOrderDirection(vector<vector<int>> &matrix) {
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
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> ret;
    const int m = matrix.size();
    if (m == 0) {
      return ret;
    }
    const int n = matrix[0].size();

    auto beginx = 0;
    auto endx = m - 1;

    auto beginy = 0;
    auto endy = n - 1;

    //    ----------> ++beginx
    // ++beginy
    //   ^                |
    //   |                |
    //   |                |
    //   |                |
    //   |                v
    // --endx<--------- --endy

    // 这里有一个规律，无论横着，竖着，反着，正着都循环里边界都很固定，
    // 个人觉得难点在更新边界，说明在更新部分
    while (true) {
      // left --> right
      for (int j = beginy; j <= endy; ++j) {
        ret.push_back(matrix[beginx][j]);
      }
      // 第一行走完了，后续的行操作都从下一行开始
      if (++beginx > endx) {
        break;
      }
      // top --> down
      for (int i = beginx; i <= endx; ++i) {
        ret.push_back(matrix[i][endy]);
      }
      // 最后一列走完，后续的列操作都到前面一列终止
      if (--endy < beginy) {
        break;
      }
      // right --> left
      for (int j = endy; j >= beginy; --j) {
        ret.push_back(matrix[endx][j]);
      }
      // 最后一行走完，行操作都到前面一行
      if (--endx < beginx) {
        break;
      }
      // down --> top
      for (int i = endx; i >= beginx; --i) {
        ret.push_back(matrix[i][beginy]);
      }
      // 第一列走完，后续列下一列开始
      if (++beginy > endy) {
        break;
      }
    }

    return ret;
  }
};

int main() {
  Solution so;
  vector<vector<int>> input{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  auto ret = so.spiralOrder(input);
  for (auto i : ret) {
    cout << i << endl;
  }

  return 0;
}
