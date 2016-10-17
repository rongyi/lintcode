// http://www.lintcode.com/zh-cn/problem/integer-to-roman
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
   * @param n The integer
   * @return Roman representation
   */
  string intToRoman(int n) {
    string ret;
    static const int radix[] = {1000, 900, 500, 400, 100, 90,
                                50, 40, 10, 9, 5, 4, 1};
    static const string symbol[] = {"M","CM", "D", "CD", "C",
                                    "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    for (int i = 0; n > 0; i++) {
      int count = n / radix[i];
      n %= radix[i];
      for (; count > 0; --count)
        ret += symbol[i];
    }

    return ret;
  }
};
