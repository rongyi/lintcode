// http://www.lintcode.com/zh-cn/problem/monotone-increasing-digits
#include <bitset>
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param num: a non-negative integer N
   * @return: the largest number that is less than or equal to N with monotone
   * increasing digits.
   */
  int monotoneDigits(int num) {
    string str = std::to_string(num);
    int n = str.size(), j = n;
    for (int i = n - 1; i > 0; --i) {
      if (str[i] >= str[i - 1])
        continue;
      --str[i - 1];
      j = i;
    }
    for (int i = j; i < n; ++i) {
      str[i] = '9';
    }
    return stoi(str);
  }

  int digitCount(int n) {
    int ret = 0;
    while (n) {
      ++ret;
      n /= 10;
    }
    return ret;
  }
};

int main() {
  Solution so;
  auto ret = so.monotoneDigits(111111110);
  cout << 111111110 << endl;
  cout << ret << endl;
}
