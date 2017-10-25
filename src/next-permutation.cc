// http://www.lintcode.com/zh-cn/problem/next-permutation

#include <vector>
using std::vector;
class Solution {
public:
  /**
   * @param nums: An array of integers
   * @return: An array of integers that's next permuation
   */
  vector<int> nextPermutation(vector<int> &nums) {
    next_permutation(nums, 0, nums.size());
    return nums;
  }

private:
  bool next_permutation(vector<int> &nums, int begin, int end) {
    // from right to left fint the first digit which violates the increase trend
    int p = end - 2;
    while (p > -1 && nums[p] >= nums[p + 1])
      --p;

    if (p == -1) {
      std::reverse(&nums[begin], &nums[end]);
      return false;
    }

    int c = end - 1;
    while (c > 0 && nums[c] <= nums[p])
      --c;

    std::swap(nums[p], nums[c]);
    std::reverse(&nums[p + 1], &nums[end]);
    return true;
  }
};
