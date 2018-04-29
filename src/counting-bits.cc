// http://www.lintcode.com/zh-cn/problem/counting-bits
#include <vector>
#include <iostream>
#include <string>
#include <bitset>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param num: a non negative integer number
   * @return: an array represent the number of 1's in their binary
   */
  vector<int> countBits(int num) {
    vector<int> ret{0};
    for (int i = 1; i <= num; ++i) {
      if (i % 2 == 0) {
        ret.push_back(ret[i / 2]);
      } else {
        ret.push_back(ret[i / 2] + 1);
      }
    }

    return ret;
  }
};
