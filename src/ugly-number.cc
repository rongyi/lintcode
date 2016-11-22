// http://www.lintcode.com/zh-cn/problem/ugly-number
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
   * @param num an integer
   * @return true if num is an ugly number or false
   */
  bool isUgly(int num) {
    if (num <= 0) {
      return false;
    }
    while (num % 2 == 0) {
      num /= 2;
    }
    while (num % 3 == 0) {
      num /= 3;
    }
    while (num % 5 == 0) {
      num /= 5;
    }

    return num == 1;
  }
};

int main()
{
  Solution so;
  auto ret = so.isUgly(33);
  cout << ret << endl;
  return 0;
}
