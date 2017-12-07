// http://www.lintcode.com/zh-cn/problem/reverse-integer
#include <climits>
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
   * @param n the integer to be reversed
   * @return the reversed integer
   */
  int reverseInteger(int n) {
    int sign = 1;
    int ret = 0;
    if (n < 0) {
      sign = -1;
      n *= -1;
    }
    // multiply the last digit repeatly
    while (n) {
      int tmp = ret * 10 + n % 10;
      if (tmp / 10 != ret)
        return 0;
      ret = tmp;
      n /= 10;
    }

    return ret * sign;
  }
};

int main() {
  Solution so;
  auto ret = so.reverseInteger(0);
  cout << ret << endl;
  return 0;
}
