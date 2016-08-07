// http://www.lintcode.com/zh-cn/problem/divide-two-integers
#include <vector>
#include <iostream>
#include <string>
#include <limits>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param dividend the dividend
   * @param divisor the divisor
   * @return the result
   */
  int divide(int dividend, int divisor) {
    if (divisor == 0)
      return -1;
    if(dividend == std::numeric_limits<int>::min() && divisor==-1)
      return std::numeric_limits<int>::max();

    int sign = 1;

    if ((dividend > 0) != (divisor > 0)) {
      sign = -1;
    }

    long long ded = std::abs((long long)dividend);
    long long der = std::abs((long long)divisor);
    long long der_copy = der;
    long long ret = 0;

    // too slow!
    // while (ded >= der) {
    //   ded -= der;
    //   if (std::numeric_limits<int>::max() - 1 == ret) {
    //     return sign > 0 ? std::numeric_limits<int>::max() : std::numeric_limits<int>::min();
    //   }
    //   ret += 1;
    // }

    // make it fast
    int step = 0;
    while (der_copy < ded) {
      der_copy <<= 1;
      step++;
    }

    while (ded >= der) {
      if (ded >= der_copy) {
        ded -= der_copy;
        ret += (long long)1 << step;
      }
      der_copy >>= 1;
      step--;
    }

    return ret * sign;
  }
};
