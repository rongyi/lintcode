// http://www.lintcode.com/zh-cn/problem/reverse-3-digit-integer

class Solution {
public:
  /**
   * @param number: A 3-digit number.
   * @return: Reversed number.
   */
  // 你可以假设输入一定是一个只有三位数的整数，这个整数大于等于100，小于1000。
  int reverseInteger(int number) {
    auto last = number % 10;
    auto mid = number / 10 % 10;
    auto first = number / 100;
    return last * 100 + mid * 10 + first;
  }
};
