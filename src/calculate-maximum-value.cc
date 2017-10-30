// http://www.lintcode.com/zh-cn/problem/calculate-maximum-value
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

class Solution {
public:
  /*
  * @param : the given string
  * @return: the maximum value
  */
  int calcMaxValue(string &str) {
    if (str.length() == 0) {
      return 0;
    }
    if (str.length() == 1) {
      return std::stoi(str);
    }
    const vector<string> ops{"+", "*"};
    auto all_ops = binaryPossible(ops, str.size() - 1);
    int ret = std::numeric_limits<int>::min();
    for (auto op : all_ops) {
      auto cur_val = applyOp(str, op);
      ret = std::max(ret, cur_val);
    }

    return ret;
  }

  vector<string> binaryPossible(const vector<string> &ops, int width) {
    const auto size = 0x1 << width;
    vector<int> all(size);
    for (auto i = 0; i < size; i++) {
      all[i] = i;
    }
    std::vector<string> ret;
    for (auto i = 0; i < size; i++) {
      std::stringstream ss;
      for (auto w = 0; w < width; w++) {
        auto cur = (i >> w) & 0x1;
        ss << ops[cur];
      }
      ret.push_back(ss.str());
    }

    return ret;
  }

  int applyOp(const string &str, const string &ops) {
    int prev = alu(str[0] - '0', str[1], ops[0]);
    for (int i = 1; i < ops.length(); i++) {
      int cur = alu(prev, str[i + 1], ops[i]);
      prev = cur;
    }
    return prev;
  }

  int alu(int left, char right, char op) {
    int ret = 0;
    switch (op) {
    case '+':
      ret = left + (right - '0');
      break;
    case '*':
      ret = left * (right - '0');
      break;
    }
    return ret;
  }

};

int main() {
  Solution so;
  string str{"11111111111111111111"};
  auto ret = so.calcMaxValue(str);
  cout << ret << endl;
  return 0;
}
