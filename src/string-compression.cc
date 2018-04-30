// http://www.lintcode.com/zh-cn/problem/string-compression
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param str: a string
   * @return: a compressed string
   */
  string compress(string &str) {
    if (str.empty()) {
      return str;
    }
    std::stringstream ss;

    char cur = str[0];
    int repeat_count = 1;
    for (int i = 1; i < str.size(); ++i) {
      if (str[i] == cur) {
        repeat_count++;
      } else {
        // construct the new
        ss << cur;
        ss << repeat_count;

        // update
        repeat_count = 1;
        cur = str[i];
      }
    }
    // the last one
    ss << cur;
    ss << repeat_count;

    auto ret = ss.str();
    // If the "compressed" string would not become smaller than the original string, your method should return the original string.
    if (ret.size() >= str.size()) {
      return str;
    }
    return ret;
  }
};
