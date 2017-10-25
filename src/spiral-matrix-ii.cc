// http://www.lintcode.com/zh-cn/problem/spiral-matrix-ii
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
   * @param n an integer
   * @return a square matrix
   */
  vector<vector<int>> generateMatrix(int num) {
    if (num <= 0) {
      return vector<vector<int>>();
    }
    vector<vector<int>> ret(num, vector<int>(num));

    int m = ret.size();
    int n = ret[0].size();

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
    int i = 1;

    while (true) {
      if (candidate_num <= 0)
        break;

      ret[startx][starty] = i++;
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

int main() {
  Solution so;
  auto ret = so.generateMatrix(3);
  for (auto vec : ret) {
    for (auto i : vec) {
      cout << i << " ";
    }
    cout << endl;
  }

  return 0;
}
