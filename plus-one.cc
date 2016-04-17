// http://www.lintcode.com/zh-cn/problem/plus-one/

#include <vector>
using std::vector;
class Solution {
public:
  /**
   * @param digits a number represented as an array of digits
   * @return the result
   */
  vector<int> plusOne(vector<int>& digits) {
    add(digits, 1);
    return digits;
  }
private:
  void add(vector<int> &digits, int digit) {
    int c = digit;
    for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
      *it += c;
      c = *it / 10;
      *it %= 10;
    }
    if (c > 0)
      digits.insert(digits.begin(), 1);
  }
};
