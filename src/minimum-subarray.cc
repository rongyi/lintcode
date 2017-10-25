// http://www.lintcode.com/zh-cn/problem/minimum-subarray
#include <cctype>
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
   * @param nums: a list of integers
   * @return: A integer denote the sum of minimum subarray
   */
  int minSubArray(vector<int> nums) {
    int ret = INT_MAX;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (sum > 0) {
        sum = nums[i];
        if (ret > sum)
          ret = sum;
      } else {
        sum += nums[i];
        if (ret > sum)
          ret = sum;
      }
    }

    return ret;
  }
};
