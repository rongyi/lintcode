// http://www.lintcode.com/zh-cn/problem/house-robber-ii
#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param nums: An array of non-negative integers.
   * return: The maximum amount of money you can rob tonight
   */
  int houseRobber2(vector<int>& nums) {
    const int n = nums.size();
    if (n == 0)
      return 0;
    if (n == 1)
      return nums[0];

    return std::max(do_robber(nums, 0, n - 1), do_robber(nums, 1, n));
  }

  int do_robber(vector<int> &nums, int left, int right) {
    if (right - left <= 1)
      return nums[left];
    vector<int> ret(right, 0);
    ret[left] = nums[left];
    ret[left + 1] = std::max(nums[left], nums[left + 1]);

    for (int i = left + 2; i < right; i++) {
      ret[i] = std::max(ret[i - 2] + nums[i], ret[i - 1]);
    }
    return ret[right - 1];
  }
};
