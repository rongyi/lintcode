// http://www.lintcode.com/zh-cn/problem/add-binary

#include <algorithm>
#include <string>
using std::string;

class Solution {
public:
  /**
   * @param a a number
   * @param b a number
   * @return the result
   */
  string addBinary1(string &a, string &b) {
    string ret;
    const size_t n = a.size() > b.size() ? a.size() : b.size();
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());
    int carry = 0;
    for (size_t i = 0; i < n; i++) {
      const int ai = i < a.size() ? a[i] - '0' : 0;
      const int bi = i < b.size() ? b[i] - '0' : 0;
      const int val = ai + bi + carry;
      carry = val / 2;
      ret.insert(ret.begin(), val % 2 + '0');
    }
    if (carry)
      ret.insert(ret.begin(), '1');
    return ret;
  }

  string addBinary(string &a, string &b) {
    string ret;

    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;
    while (i >= 0 || j >= 0 || carry > 0) {
      int ai = i < 0 ? 0 : a[i--] - '0';
      int bi = j < 0 ? 0 : b[j--] - '0';
      int sum = ai + bi + carry;
      ret.insert(ret.begin(), (sum % 2) + '0');
      carry = sum / 2;
    }

    return ret;
  }
};
