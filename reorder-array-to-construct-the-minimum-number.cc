// http://www.lintcode.com/zh-cn/problem/reorder-array-to-construct-the-minimum-number
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param nums n non-negative integer array
   * @return a string
   */
  string minNumber(vector<int>& nums) {
    auto cmp = [](int i, int j) {
      auto si = std::to_string(i);
      auto sj = std::to_string(j);
      return si + sj < sj + si;
    };

    std::sort(nums.begin(), nums.end(), cmp);
    std::stringstream ss;
    for (auto &i : nums)
      ss << i;
    auto ret = ss.str();

    if (ret.find_first_not_of("0") == std::string::npos) {
      return "0";
    }

    return ret.substr(ret.find_first_not_of("0"));
  }
};

int main()
{
  Solution so;
  vector<int> test{0};
  auto ret = so.minNumber(test);
  cout << ret << endl;
  return 0;
}
