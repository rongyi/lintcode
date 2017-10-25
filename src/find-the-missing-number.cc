// http://www.lintcode.com/zh-cn/problem/find-the-missing-number
#include <algorithm>
#include <iostream>
#include <vector>
using std::vector;

class Solution {
public:
  /**
   * @param nums: a vector of integers
   * @return: an integer
   */
  // very lame
  int findMissingLame(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != i)
        return i;
    }
    return nums.size();
  }
  int findMissing(vector<int> &nums) {
    int ret = 0;

    for (int i = 0; i < nums.size() + 1; i++) {
      ret ^= i;
    }
    for (int i = 0; i < nums.size(); i++) {
      ret ^= nums[i];
    }
    return ret;
  }
};
