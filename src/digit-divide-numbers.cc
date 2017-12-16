// http://www.lintcode.com/zh-cn/problem/digit-divide-numbers
#include <iostream>
#include <limits>
#include <string>
#include <unordered_set>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param lower: Integer : lower bound
   * @param upper: Integer : upper bound
   * @return: a list of every possible Digit Divide Numbers
   */
  vector<int> digitDivideNums(int lower, int upper) {
    vector<int> ret;
    for (int i = lower; i <= upper; ++i) {
      if (isdn(i)) {
        ret.push_back(i);
      }
      // incase overflow
      if (std::numeric_limits<int>::max() == i) {
        break;
      }
    }
    return ret;
  }

  // string process is fast than digit
  bool isdn(long long num) {
    string str = std::to_string(num);
    for (char c : str) {
      if (c == '0' || num % (c - '0')) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution so;
  auto ret = so.digitDivideNums(2147483000, 2147483647);
  for (auto i : ret) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
