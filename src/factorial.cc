// http://www.lintcode.com/zh-cn/problem/factorial
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

using std::vector;
using std::cout;
using std::endl;
using std::string;


class Solution {
public:
  /*
  * @param : an integer
  * @return:  the factorial of n
  * from chenshuo:
  * https://github.com/chenshuo/recipes/blob/master/basic/tutorial/factorial.cc
  */
  string factorial(int n) {
    auto ret = fac(n);
    return to_string(ret);
  }

  vector<int> fac(int n) {
    vector<int> result;
    result.push_back(1);
    for (int factor = 1; factor <= n; ++factor) {
      int carry = 0;
      for (auto &item : result) {
        int product = item * factor + carry;
        item = product % 10000;
        carry = product / 10000;
      }
      if (carry > 0) {
        result.push_back(carry);
      }
    }
    return result;
  }

  string to_string(const vector<int> &number) {
    std::stringstream ss;

    ss << number.back();
    for (auto it = number.rbegin() + 1; it != number.rend(); ++it) {
      ss << std::setfill('0') << std::setw(4) << *it;
    }

    return ss.str();
  }
};

int main() {

  return 0;
}
