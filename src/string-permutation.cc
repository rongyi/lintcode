// http://www.lintcode.com/zh-cn/problem/string-permutation

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;
class Solution {
public:
  /**
   * @param A a string
   * @param B a string
   * @return a boolean
   */
  bool stringPermutation(string &a, string &b) {
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    return a == b;
  }
};
