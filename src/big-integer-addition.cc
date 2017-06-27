// http://www.lintcode.com/zh-cn/problem/big-integer-addition
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

class Solution {
public:
  /**
   * @param num1 a non-negative integers
   * @param num2 a non-negative integers
   * @return return sum of num1 and num2
   */
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
      int cur = sum % 10;
      ss << cur;
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
  string num1 = "1";
  string num2 = "999";
  auto ret = so.addStrings(num1, num2);
  cout << ret << endl;
  return 0;
}
