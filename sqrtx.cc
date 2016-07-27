// http://www.lintcode.com/zh-cn/problem/sqrtx
#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;


class Solution {
public:
  /**
   * @param x: An integer
   * @return: The sqrt of x
   */
  int sqrt(int x) {
    int low = 0;
    int high = x;
    while (low <= high) {
      const int mid = low + (high - low) / 2;
      long square = (long)mid * (long)mid;
      long squareplus = (long)(mid + 1) * (long)(mid + 1);
      long squareminus = (long)(mid - 1) * (long)(mid - 1);
      if (x == square) {
        return mid;
      } else if (x > square && x < squareplus) {
        return mid;
      } else if (x < square && x > squareminus) {
        return mid - 1;
      } else if (x > square) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return -1;
  }
};
