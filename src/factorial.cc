// http://www.lintcode.com/zh-cn/problem/factorial
#include <vector>
#include <iostream>
#include <string>
#include <limits>
#include <algorithm>

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
    auto ret = std::to_string(n);
    for (int i = n - 1; i >= 1; --i) {
      auto s2 = std::to_string(i);
      auto multi = multiply(ret, s2);
      ret = multi;
    }

    return ret;
  }
private:
  int fac(int i) {
    if (i == 0) {
      return 1;
    }
    return i * fac(i - 1);
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

int main()
{
  Solution so;
  return 0;
}
