// http://www.lintcode.com/zh-cn/problem/space-replacement
#include <vector>
#include <iostream>
#include <string>
#include <cstring>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param string: An array of Char
   * @param length: The true length of the string
   * @return: The true length of new string
   */
  int replaceBlank(char string[], int length) {
    if (!string)
      return 0;
    const int len = std::strlen(string);
    int space_count = 0;
    for (int i = 0; i < len; i++) {
      if (*(string + i) == ' ')
        ++space_count;
    }
    std::string copy(string);
    for (auto c : copy) {
      if (c == ' ') {
        *(string++) = '%';
        *(string++) = '2';
        *(string++) = '0';
      } else {
        *(string++) = c;
      }

    }
    return len + space_count * 2;
  }
};
