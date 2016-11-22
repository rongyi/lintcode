// http://www.lintcode.com/zh-cn/problem/find-the-missing-number
#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
  /**
   * @param nums: a vector of integers
   * @return: an integer
   */
  int findMissing(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != i)
        return i;
    }
    return nums.size();
  }
};
