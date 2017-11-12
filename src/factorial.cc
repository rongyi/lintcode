// http://www.lintcode.com/zh-cn/problem/factorial
#include <vector>
#include <iostream>
#include <string>
#include <limits>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /*
  * @param : an integer
  * @return:  the factorial of n
  */
  string factorial(int n) {
    // int over flow range
    if (n <= 16) {
      auto f = fac(n);
      return std::to_string(f);
    }
    // string multiply
    return "";
  }
private:
  int fac(int i) {
    if (i == 0) {
      return 1;
    }
    return i * fac(i - 1);
  }
};

int main()
{
  Solution so;
  return 0;
}
