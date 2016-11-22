// http://www.lintcode.com/zh-cn/problem/count-1-in-binary/

class Solution {
public:
  /**
   * @param num: an integer
   * @return: an integer, the number of ones in num
   */
  int countOnes(int num) {
    int ret = 0;

    while (num) {
      ++ret;
      num = num & (num - 1);
    }

    return ret;
  }
};
