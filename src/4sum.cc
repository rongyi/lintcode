// http://www.lintcode.com/zh-cn/problem/4sum
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

using std::unordered_map;
class Solution {
public:
  /**
   * @param numbers: Give an array numbersbers of n integer
   * @param target: you need to find four elements that's sum of target
   * @return: Find all unique quadruplets in the array which gives the sum of
   *          zero.
   */
  vector<vector<int>> fourSum(vector<int> nums, int target) {
    vector<vector<int>> ret;
    if (nums.empty() || nums.size() <= 3)
      return ret;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 3; i++) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      int j = i + 1;
      for (; j < nums.size() - 2; j++) {
        if (j > i + 1 && nums[j] == nums[j - 1])
          continue;

        int left = j + 1;
        int right = nums.size() - 1;
        while (left < right) {
          int sum = nums[i] + nums[j] + nums[left] + nums[right];
          if (sum == target) {
            vector<int> cur_ret;
            cur_ret.push_back(nums[i]);
            cur_ret.push_back(nums[j]);
            cur_ret.push_back(nums[left]);
            cur_ret.push_back(nums[right]);
            ret.push_back(cur_ret);

            left++;
            right--;
            while (left < right && nums[left] == nums[left - 1])
              left++;

            while (left < right && nums[right] == nums[right + 1])
              right--;
          } else if (sum > target) {
            right--;
          } else {
            left++;
          }
        }
      }
    }

    return ret;
  }
};
