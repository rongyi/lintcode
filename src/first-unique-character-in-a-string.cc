// http://www.lintcode.com/zh-cn/problem/first-unique-character-in-a-string
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
   * @param str: str: the given string
   * @return: char: the first unique character in a given string
   */
  char firstUniqChar(string &str) {
    char map[256] = {};
    for (auto c : str) {
      map[int(c)]++;
    }
    for (auto c : str) {
      if (map[int(c)] == 1) {
        return c;
      }
    }
    return '0';
  }
};
