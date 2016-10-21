// http://www.lintcode.com/zh-cn/problem/scramble-string
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param s1 A string
   * @param s2 Another string
   * @return whether s2 is a scrambled string of s1
   */
  bool isScramble(string& s1, string& s2) {
    if (s1 == s2)
      return true;
    if (s1.empty() || s2.empty())
      return false;
    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());
    if (s1 != s2)
      return false;
    for (int i = 1; i < s1.size(); i++) {
      return isScramble(s1.substr(0, i), s2.substr(0, i)) &&
        isScramble(s1.substr(i), s2.substr(i));
    }

    return false;
  }
};
