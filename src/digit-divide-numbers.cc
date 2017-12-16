// http://www.lintcode.com/zh-cn/problem/digit-divide-numbers
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

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

    }
  }

  bool isdn(int n) {
    if (n == 0) {
      return false;
    } else if (n < 10) {
      return true;
    }
    std::unordered_set<int> ds;
    while (n) {
      auto d = n % 10;
      if (d == 0) {
        return false;
      }
      ds.insert(d);
      n /= 10;
    }
    if (ds.find(2) != ds.end() && (n & 0x1)) {
      return false;
    }
    for (auto iter = ds.begin(); iter != ds.end(); ++iter) {
      if (n % (*iter) != 0) {
        return false;
      }
    }

    return true;
  }
};
