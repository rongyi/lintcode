// http://www.lintcode.com/zh-cn/problem/rotate-bits-left

class Solution {
public:
  /*
  * @param : a number
  * @param : digit needed to be rorated
  * @return: a number
  */
  int leftRotate(int n, int d) {
    int higer = n >> (32 - d);
    return (n << d) | higer;
  }
};
