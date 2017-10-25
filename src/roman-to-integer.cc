// http://www.lintcode.com/zh-cn/problem/roman-to-integer
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
   * @param s Roman representation
   * @return an integer
   */
  int romanToInt(string &s) {
    auto map = [](const char c) -> int {
      switch (c) {
      case 'I':
        return 1;
      case 'V':
        return 5;
      case 'X':
        return 10;
      case 'L':
        return 50;
      case 'C':
        return 100;
      case 'D':
        return 500;
      case 'M':
        return 1000;
      default:
        return 0;
      }
    };
    int ret = 0;

    for (int i = 0; i < s.size(); i++) {
      if (i > 0 && map(s[i]) > map(s[i - 1])) {
        ret += (map(s[i]) - 2 * map(s[i - 1]));
      } else {
        ret += map(s[i]);
      }
    }

    return ret;
  }
};
