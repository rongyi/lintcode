// http://www.lintcode.com/zh-cn/problem/rearrange-a-string-with-integers
#include <bitset>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /*
  * @param str: a string containing uppercase alphabets and integer digits
  * @return: the alphabets in the order followed by the sum of digits
  */
  string rearrange(string &str) {
    if (str == "") {
      return "";
    }
    string s;
    int sum = 0;
    for (auto c : str) {
      if (c <= '9' && c >= '0') {
        sum += c - '0';
      } else {
        s += string(1, c);
      }
    }
    std::sort(s.begin(), s.end());
    return s + std::to_string(sum);
  }
};
