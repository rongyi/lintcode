// http://www.lintcode.com/zh-cn/problem/house-robber-ii
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
   * @param nums: An array of non-negative integers.
   * return: The maximum amount of money you can rob tonight
   */
  int houseRobber2(vector<int> &nums) {
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
    const int n = right - left;
    vector<int> ret(n, 0);
    ret[0] = nums[left];
    ret[1] = std::max(nums[left], nums[left + 1]);

    for (int i = 2; i < n; i++) {
      ret[i] = std::max(ret[i - 2] + nums[i + left], ret[i - 1]);
    }
    return ret[n - 1];
  }
};
