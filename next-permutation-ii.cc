// http://www.lintcode.com/zh-cn/problem/next-permutation-ii
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
   * @return: return nothing (void), do not return anything, modify nums in-place instead
   */
  void nextPermutation(vector<int> &nums) {
    int j = -1;
    int k = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
      if (nums[i] < nums[i + 1])
        j = i;
    }

    if (j >= 0) {
      for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] > nums[j]) {
          k = i;
        }
      }
      std::swap(nums[j], nums[k]);
    }

    std::reverse(nums.begin() + j + 1, nums.end());
  }
};
