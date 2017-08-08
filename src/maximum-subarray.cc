// http://www.lintcode.com/zh-cn/problem/maximum-subarray
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
   * @param nums: A list of integers
   * @return: A integer indicate the sum of max subarray
   */
  int maxSubArray(vector<int> nums) {
    if (!nums.size())
      return 0;
    const int n = nums.size();
    int cur_sum = 0;
    int max_sum = nums[0];

    for (int i = 0; i < n; i++) {
      // 新来的一个数有两个选择
      // 1. 加入前面的子数组
      // 2. 不加入前面的子数组，作为新的数组的第一个元素
      // 判断的标准？ 加上之前的和是否对自己有利
      cur_sum = (nums[i] > cur_sum + nums[i]) ? nums[i] : cur_sum + nums[i];
      if (cur_sum > max_sum)
        max_sum = cur_sum;
    }
    return max_sum;
  }
};
