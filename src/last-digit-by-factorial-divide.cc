// http://www.lintcode.com/zh-cn/problem/last-digit-by-factorial-divide
class Solution {
public:
  /*
  * @param : the given number
  * @param : another number
  * @return: the last digit of B! / A!
  */
  int computeLastDigit(long long a, long long b) {
    if (a == b) {
      return 1;
    }
    if (b - a >= 5) {
      return 0;
    }

    int mul = 1;
    for (long long i = a + 1; i <= b; ++i) {
      mul = (mul * (i % 10)) % 10;
    }
    return mul % 10;
  }
};
