// http://www.lintcode.com/zh-cn/problem/backpack
#include <vector>
#include <iostream>
#include <string>
#include <cstring>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param m: An integer m denotes the size of a backpack
   * @param A: Given n items with size A[i]
   * @return: The maximum size
   */
  int backPack(int m, vector<int> A) {
    const int n = A.size();
    if (m <= 0 || A.empty())
      return 0;
    bool ret[n + 1][m + 1];

    ret[0][0] = true;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        if (j - A[i - 1] >= 0) {
          ret[i][j] = ret[i - 1][j] || ret[i - 1][j - A[i - 1]];
        } else {
          ret[i][j] = ret[i - 1][j];
        }
      }
    }

    for (int j = m; j >= 0; j--) {
      if (ret[n][j])
        return j;
    }

    return 0;
  }
};
