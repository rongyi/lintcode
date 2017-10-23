// http://www.lintcode.com/zh-cn/problem/check-sum-of-square-numbers
#include <bitset>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /*
  * @param : the given number
  * @return: whether whether there're two integers
  */
  bool checkSumOfSquareNumbers(int num) {
    if (num < 0) {
      return false;
    }
    if (num % 4 == 3)
      return false;
    auto lower = int(::sqrt(num));

    int i = lower;
    if (i * i == num) {
      return true;
    }
    int j = 1;
    while (j <= i) {
      auto check = i * i + j * j;
      if (check == num) {
        return true;
      } else if (check < num) {
        j++;
      } else {
        i--;
      }
    }
    return false;
  }
};

int main() {
  Solution so;
  auto ret = so.checkSumOfSquareNumbers(2082279424);
  cout << ret << endl;
  return 0;
}
