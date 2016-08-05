// http://www.lintcode.com/zh-cn/problem/median
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
   * @param nums: A list of integers.
   * @return: An integer denotes the middle number of the array.
   */
  int median(vector<int> &nums) {
    if (nums.empty())
      return 0;
    std::sort(nums.begin(), nums.end());
    const int n = nums.size();
    if (n & 1) {
      return nums[n / 2];
    } else {
      return (nums[n / 2 - 1] + nums[n / 2]) / 2;
    }
  }
};
