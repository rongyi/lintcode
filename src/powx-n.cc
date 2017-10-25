// http://www.lintcode.com/zh-cn/problem/powx-n/

class Solution {
public:
  /**
   * @param x the base number
   * @param n the power number
   * @return the result
   */
  double myPow(double x, int n) {
    // Write your code here
    if (x == 0)
      return 0;
    if (n < 0)
      return 1 / myPow(x, -n);
    if (n == 0)
      return 1;
    if (n & 0x1) {
      return x * myPow(x, n - 1);
    } else {
      return myPow(x, n / 2) * myPow(x, n / 2);
    }
  }
};
