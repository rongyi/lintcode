// http://www.lintcode.com/zh-cn/problem/backpack-ii
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
   * @param m: An integer m denotes the size of a backpack
   * @param A & V: Given n items with size A[i] and value V[i]
   * @return: The maximum value
   */
  int backPackII(int m, vector<int> A, vector<int> V) {
    const int n = A.size();
    if (m <= 0 || A.empty() || V.empty())
      return 0;
    vector<vector<int>> ret(n + 1, vector<int>(m + 1, 0));
    ret[0][0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        if (j - A[i - 1] < 0)
          ret[i][j] = ret[i - 1][j];
        else
          ret[i][j] =
              std::max(ret[i - 1][j], ret[i - 1][j - A[i - 1]] + V[i - 1]);
      }
    }

    return ret[n][m];
  }
};
