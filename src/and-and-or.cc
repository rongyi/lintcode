// http://www.lintcode.com/zh-cn/problem/and-and-or
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param n:
   * @param nums:
   * @return: return the sum of maximum OR sum, minimum OR sum, maximum AND sum, minimum AND sum.
   */
  long long getSum(int n, vector<int> &nums) {
    auto or_min = *std::min_element(nums.begin(), nums.end());
    auto and_max = *std::max_element(nums.begin(), nums.end());
    auto or_max = 0;
    for (int i = 0; i < n; i++) {
      or_max |= nums[i];
    }
    auto and_min = nums[0];
    for (int i = 1; i < n; i++) {
      auto tmp = and_min & nums[i];
      and_min = std::min(tmp, and_min);
    }

    return or_min + and_max + or_max + and_min;
  }
};
