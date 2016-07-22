// http://www.lintcode.com/zh-cn/problem/left-pad
#include <string>
#include <iostream>
#include <sstream>

using std::string;
using std::cout;
using std::endl;
using std::stringstream;

class StringUtils {
public:
  /**
   * @param originalStr the string we want to append to
   * @param size the target length of the string
   * @param padChar the character to pad to the left side of the string
   * @return a string
   */
  static string leftPad(string& originalStr, int size, char padChar=' ') {
    const int len = originalStr.length();
    // no need to padding
    if (len >= size) {
      return originalStr;
    }
    stringstream ss;
    for (int i = 0; i < size - len; i++) {
      ss << padChar;
    }
    ss << originalStr;
    return ss.str();
  }
};
