// http://www.lintcode.com/zh-cn/problem/print-numbers-by-recursion
#include <cmath>
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
   * @param n: An integer.
   * return : An array storing 1 to the largest number with n digits.
   */
  vector<int> numbersByRecursion(int n) {
    vector<int> ret;
    if (n <= 0) {
      return ret;
    } else if (n == 1) {
      return {1, 2, 3, 4, 5, 6, 7, 8, 9};
    } else {
      auto prev = numbersByRecursion(n - 1);
      std::copy(prev.begin(), prev.end(), std::back_inserter(ret));
      for (int i = 1; i <= 9; i++) {
        ret.push_back(::pow(10, n - 1) * i);
        for (auto p : prev) {
          ret.push_back(::pow(10, n - 1) * i + p);
        }
      }
      return ret;
    }
  }
};
