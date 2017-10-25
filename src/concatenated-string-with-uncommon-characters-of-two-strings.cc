// http://www.lintcode.com/zh-cn/problem/concatenated-string-with-uncommon-characters-of-two-strings
#include <bitset>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::unordered_set;

class Solution {
public:
  /*
  * @param : the 1st string
  * @param : the 2nd string
  * @return: uncommon characters of given strings
  * embrassing simple
  */
  string concatenetedString(string &s1, string &s2) {
    unordered_set<char> set1;
    unordered_set<char> inter;
    for (auto &s : s1) {
      set1.insert(s);
    }
    for (auto &s : s2) {
      if (set1.find(s) != set1.end()) {
        inter.insert(s);
      }
    }
    std::stringstream ss;
    for (auto s : s1) {
      if (inter.find(s) == inter.end()) {
        ss << s;
      }
    }
    for (auto s : s2) {
      if (inter.find(s) == inter.end()) {
        ss << s;
      }
    }
    return ss.str();
  }
};
