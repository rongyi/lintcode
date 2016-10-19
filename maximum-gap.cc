// http://www.lintcode.com/zh-cn/problem/maximum-gap
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
   * @param nums: a vector of integers
   * @return: the maximum difference
   */
  int maximumGap(vector<int> &nums) {
    if (nums.size() < 2)
      return 0;
    std::sort(nums.begin(), nums.end());
    int ret = std::numeric_limits<int>::min();
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] - nums[i - 1] > ret)
        ret = nums[i] - nums[i - 1];
    }

    return ret;
  }
};
