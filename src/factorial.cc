// http://www.lintcode.com/zh-cn/problem/factorial
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <sstream>

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
    if (n <= 20) {
      auto f = fac(n);
      return std::to_string(f);
    }

    // string multiply
    auto sfact20 = std::to_string(fac(20));
    auto ret = std::to_string(n);
    for (int i = n - 1; i > 20; --i) {
      auto s2 = std::to_string(i);
      // auto multi = multiply2(ret, s2);
      ret = multiply2(ret, s2);
    }
    // the rest 16
    ret = multiply2(ret, sfact20);

    return ret;
  }
  // to test overflow
  void print() {
    auto max = std::numeric_limits<uint64_t>::max();
    for (int i = 0; i < 23; i++) {
      cout << i << ":  " << fac(i) << endl << "     " << max << endl;
    }
  }

private:
  uint64_t fac(int n) {
    if (n == 0) {
      return 1;
    }
    uint64_t ret = 1;
    for (uint64_t i = 1; i <= uint64_t(n); ++i) {
      ret *= i;
    }
    return ret;
  }

  // Multiplies str1 and str2, and prints result.
  string multiply2(string num1, string num2) {
    int n1 = num1.size();
    int n2 = num2.size();
    if (n1 == 0 || n2 == 0)
      return "0";

    // will keep the result number in vector
    // in reverse order
    vector<int> result(n1 + n2, 0);

    // Below two indexes are used to find positions
    // in result.
    int i_n1 = 0;
    int i_n2 = 0;

    // Go from right to left in num1
    for (int i = n1 - 1; i >= 0; i--) {
      int carry = 0;
      int n1 = num1[i] - '0';

      // To shift position to left after every
      // multiplication of a digit in num2
      i_n2 = 0;

      // Go from right to left in num2
      for (int j = n2 - 1; j >= 0; j--) {
        // Take current digit of second number
        int n2 = num2[j] - '0';

        // Multiply with current digit of first number
        // and add result to previously stored result
        // at current position.
        int sum = n1 * n2 + result[i_n1 + i_n2] + carry;

        // Carry for next iteration
        carry = sum / 10;

        // Store result
        result[i_n1 + i_n2] = sum % 10;

        i_n2++;
      }

      // store carry in next cell
      if (carry > 0)
        result[i_n1 + i_n2] += carry;

      // To shift position to left after every
      // multiplication of a digit in num1.
      i_n1++;
    }

    // ignore '0's from the right
    int i = result.size() - 1;
    while (i >= 0 && result[i] == 0)
      i--;

    // If all were '0's - means either both or
    // one of num1 or num2 were '0'
    if (i == -1)
      return "0";

    // generate the result string
    string s = "";
    while (i >= 0)
      s += std::to_string(result[i--]);

    return s;
  }

  /**
   * @param num1 a non-negative integers
   * @param num2 a non-negative integers
   * @return return product of num1 and num2
   */
  string multiply(string &num1, string &num2) {
    vector<string> ret;
    for (int i = num2.size() - 1; i >= 0; i--) {
      int carry = 0;
      std::stringstream ss;

      for (int j = num1.size() - 1; j >= 0; j--) {
        int mulret = (num1[j] - '0') * (num2[i] - '0') + carry;
        ss << (mulret % 10);
        carry = mulret / 10;
      }
      if (carry != 0) {
        ss << carry;
      }
      string cur_ret = ss.str();
      std::reverse(cur_ret.begin(), cur_ret.end());
      // shift
      for (int k = 0; k < (num2.size() - i - 1); k++) {
        cur_ret += "0";
      }
      ret.push_back(cur_ret);
    }
    string sum;
    for (int i = 0; i < ret.size(); i++) {
      sum = addStrings(sum, ret[i]);
    }
    // reduce zero,
    // FIXME: may be write some continue stmt in the process above
    if (std::count(sum.begin(), sum.end(), '0') == sum.size()) {
      return "0";
    }

    return sum;
  }

private:
  string addStrings(string &num1, string &num2) {
    std::reverse(num1.begin(), num1.end());
    std::reverse(num2.begin(), num2.end());
    std::stringstream ss;
    int len = std::max(num1.size(), num2.size());
    int carry = 0;
    for (int i = 0; i < len; i++) {
      int cur1 = (i < num1.size() ? (num1[i] - '0') : 0);
      int cur2 = (i < num2.size() ? (num2[i] - '0') : 0);
      int sum = cur1 + cur2 + carry;
      ss << (sum % 10);
      carry = sum / 10;
    }

    if (carry != 0) {
      ss << carry;
    }

    string ret = ss.str();
    std::reverse(ret.begin(), ret.end());
    return ret;
  }
};

int main() {
  Solution so;
  auto ret = so.factorial(2000);
  cout << ret << endl;
  // so.print();
  return 0;
}
