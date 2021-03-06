// http://www.lintcode.com/zh-cn/problem/edit-distance-ii
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
   * @param s a string
   * @param t a string
   * @return true if they are both one edit distance apart or false
   */
  bool isOneEditDistance(string &s, string &t) {
    // assume s is the short one
    if (s.size() > t.size()) {
      std::swap(s, t);
    }
    const int len_delta = t.size() - s.size();
    if (len_delta > 2) {
      return false;
    }
    if (len_delta == 1) {
      for (uint32_t i = 0; i < s.size(); ++i) {
        if (s[i] != t[i]) {
          return s.substr(i) == t.substr(i + 1);
        }
      }
    } else if (len_delta == 0) {
      int diff_count = 0;
      for (uint32_t i = 0; i < s.size(); ++i) {
        if (s[i] != t[i]) {
          diff_count++;
        }
      }
      return diff_count == 1;
    }
    return true;
  }
};
