// http://www.lintcode.com/zh-cn/problem/a-b-problem

class Solution {
public:
  /*
   * @param a: The first integer
   * @param b: The second integer
   * @return: The sum of a and b
   */
  int aplusb(int a, int b) {
    while (b != 0) {
      int carry = a & b;
      a = a ^ b;
      b = carry << 1;
    }
    return a;
  }
};
