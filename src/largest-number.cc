// http://www.lintcode.com/zh-cn/problem/largest-number
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Solution {
public:
  /**
   *@param num: A list of non negative integers
   *@return: A string
   */
  string largestNumber(vector<int> &nums) {
    sort(nums.begin(), nums.end(), [](const int &a, const int &b) -> bool {
      auto s1 = to_string(a);
      auto s2 = to_string(b);
      return s1 + s2 > s2 + s1;
    });
    stringstream ss;
    for (auto i : nums) {
      ss << i;
    }
    auto ret = ss.str();
    return ret[0] == '0' ? "0" : ret;
  }
};

int main() {
  Solution so;
  vector<int> test{1, 20, 23, 4, 8};
  auto ret = so.largestNumber(test);

  cout << ret << endl;
  return 0;
}
