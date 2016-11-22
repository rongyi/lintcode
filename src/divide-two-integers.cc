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

    long long num = std::abs((long long)dividend);
    long long diver = std::abs((long long)divisor);
    long long der_copy = diver;
    long long ret = 0;

    // too slow!
    // while (num >= diver) {
    //   num -= diver;
    //   if (std::numeric_limits<int>::max() - 1 == ret) {
    //     return sign > 0 ? std::numeric_limits<int>::max() : std::numeric_limits<int>::min();
    //   }
    //   ret += 1;
    // }

    // make it fast
    int step = 0;
    while (der_copy < num) {
      der_copy <<= 1;
      step++;
    }

    while (num >= diver) {
      if (num >= der_copy) {
        num -= der_copy;
        ret += (long long)1 << step;
      }
      der_copy >>= 1;
      step--;
    }

    return ret * sign;
  }
};
