// http://www.lintcode.com/zh-cn/problem/o1-check-power-of-2
class Solution {
public:
  /*
   * @param n: An integer
   * @return: True or false
   */
  bool checkPowerOf2(int n) {
    if (n <= 0)
      return false;
    return !(n & n - 1);
  }
};
