// http://www.lintcode.com/zh-cn/problem/perfect-squares
#include <cmath>

class Solution {
public:
  /**
   * @param n a positive integer
   * @return an integer
   */
  int numSquares(int n) {
    while (n % 4 == 0) n /= 4;
    if (n % 8 == 7) return 4;
    for (int a = 0; a * a <= n; ++a) {
      int b = std::sqrt(n - a * a);
      if (a * a + b * b == n) {
        return !!a + !!b;
      }
    }
    return 3;
  }
};
