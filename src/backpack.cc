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
    /*
      s1: D[i][j]:  bool array ---- whether the amount j can be filled with the beginning i items;
      s2: If not put current item into backpack: D[i][j] = D[i-1][j]
      if put it into backpack: D[i][j] = D[i-1][j - A[i]]
      s3: Initial condition: 0 <= i <= A.size()    0 <= j <= m
      D[0][0] = 1;  D[0][j] = 0; D[i][0] = 1;
     */
    vector<vector<bool>> ret(n + 1, vector<bool>(m + 1, false));

    ret[0][0] = true;
    for (int i = 1; i <= n; i++) {
      ret[i][0] = true;
    }
    for (int j = 1; j <= m; j++) {
      ret[0][j] = false;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (j < A[i - 1]) {
          ret[i][j] = ret[i - 1][j];
        } else {
          ret[i][j] = ret[i - 1][j] || ret[i - 1][j - A[i - 1]];
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
