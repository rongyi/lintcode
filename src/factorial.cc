// http://www.lintcode.com/zh-cn/problem/factorial
#include <algorithm>
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

// each element < 10000
// LSB first, ie. little endian
typedef std::vector<int> BigInt;

class Solution {
public:
  /*
  * @param : an integer
  * @return:  the factorial of n
  */
  string factorial(int n) {
    auto ret = fac(n);
    return printBigInt(ret);
  }

  BigInt fac(int n) {
    // 9999 * 9999 < 10000 * 10000 = 100000000 < 1073741824  = 2 ** 30
    // assert(n >= 0 && n <= 10000);

    BigInt result;
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

  string printBigInt(const BigInt &number) {
    std::stringstream ss;

    if (number.empty()) {
      ss << "0";
      printf("0\n"); // compiles to puts()
    } else {
      // printf("%d", number.back());
      ss << number.back();
      for (auto it = number.rbegin() + 1; it != number.rend(); ++it) {
        // printf("%04d", *it);
        ss << std::setfill('0') << std::setw(4) << *it;
      }
      // printf("\n");
    }
    return ss.str();
  }
};

int main() {
  return 0;
}
