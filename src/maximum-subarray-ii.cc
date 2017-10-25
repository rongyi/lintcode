// http://www.lintcode.com/zh-cn/problem/maximum-subarray-ii
#include <climits>
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
   * @param nums: A list of integers
   * @return: An integer denotes the sum of max two non-overlapping subarrays
   */
  int maxTwoSubArrays(vector<int> nums) {
    if (nums.size() < 2)
      return 0;

    int ret = INT_MIN;
    const int n = nums.size();

    vector<int> left_max(n);

    int cur_max = 0;
    for (int i = 0; i < n; i++) {
      cur_max = std::max(cur_max + nums[i], nums[i]);
      if (i == 0) {
        left_max[i] = nums[i];
      } else {
        left_max[i] = std::max(cur_max, left_max[i - 1]);
      }
    }

    cur_max = 0;

    // no need to cache, cause we calculate the final ret every round
    int right_max = 0;
    int right_min = 0;
    for (int i = n - 1; i > 0; i--) {
      cur_max = std::max(cur_max + nums[i], nums[i]);

      if (i == n - 1) {
        right_max = nums[i];
        right_min = nums[i];
      } else {
        right_max = std::max(cur_max, right_max);
      }
      ret = std::max(ret, right_max + left_max[i - 1]);
    }

    return ret;
  }
};
