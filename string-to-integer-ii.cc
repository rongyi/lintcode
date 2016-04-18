// http://www.lintcode.com/zh-cn/problem/string-to-integer-ii

#include <cstdlib>
#include <string>
#include <climits>
using std::string;
class Solution {
public:
  /**
   * @param str: A string
   * @return An integer
   */
  int atoi(string str) {
    int ret = 0;
    int sign = 1;
    const int n = str.size();
    int i = 0;
    // ignore leading spaces
    while (str[i] == ' ' && i < n)
      i++;

    if (str[i] == '+') {
      i++;
    } else if (str[i] == '-') {
      i++;
      sign = -1;
    }
    for (; i < n; i++) {
      if (str[i] < '0' || str[i] > '9')
        break;
      if (ret > INT_MAX / 10 ||
          (ret == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10)) {
        return sign == -1 ? INT_MIN : INT_MAX;
      }
      ret = ret * 10 + (str[i] - '0');
    }

    return ret * sign;
  }
};

// int main(int argc, char *argv[])
// {
//   Solution so;
//   so.atoi("10");
//   return 0;
// }
