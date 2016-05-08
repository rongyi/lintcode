// http://www.lintcode.com/zh-cn/problem/flip-bits

#include <iostream>
class Solution {
public:
  /**
   *@param a, b: Two integer
   *return: An integer
   */
  int bitSwapRequired(int a, int b) {
    int ret = 0;
    int c = a ^ b;
    while (c) {
      ret += 1;
      c &= c-1;
    }
    return ret;
  }
};

int main(int argc, char *argv[])
{
  Solution so;
  auto ret = so.bitSwapRequired(31, 14);
  std::cout << ret << std::endl;
  return 0;
}
