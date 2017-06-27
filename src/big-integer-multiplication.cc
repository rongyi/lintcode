// http://www.lintcode.com/zh-cn/problem/big-integer-multiplication
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param num1 a non-negative integers
   * @param num2 a non-negative integers
   * @return return product of num1 and num2
   */
  string multiply(string& num1, string& num2) {
    vector<string> ret;
    bool all_zero = true;
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
    if (std::count(sum.begin(), sum.end(), '0') == sum.size()) {
      return "0";
    }

    return sum;
  }
private:
  string addStrings(string& num1, string& num2) {
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
  string test1("123456789");
  string test2("0");

  auto ret = so.multiply(test1, test2);

  cout << ret << endl;
  return 0;
}
