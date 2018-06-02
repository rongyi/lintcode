// http://www.lintcode.com/zh-cn/problem/sum-of-first-k-even-length-palindrome-numbers
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Solution {
public:
  /**
   * @param k: Write your code here
   * @return: the sum of first k even-length palindrome numbers
   */
  int sumKEven(int k) {
    int ret = 0;
    for (int i = 1; i <= k; ++i) {
      ret += topalin(i);
    }

    return ret;
  }

private:
  int topalin(int n) {
    string ns = std::to_string(n);
    string cp = ns;
    std::reverse(cp.begin(), cp.end());
    return std::stoi(ns + cp);
  }
};
