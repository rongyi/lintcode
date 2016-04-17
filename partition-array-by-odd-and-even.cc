// http://www.lintcode.com/zh-cn/problem/partition-array-by-odd-and-even/

class Solution {
public:
  /**
   * @param nums: a vector of integers
   * @return: nothing
   */
  void partitionArray(vector<int> &nums) {
    int i = 0;
    int j = nums.size() - 1;
    while (i < j) {
      while (i < j && nums[i] % 2 == 1)
        i++;
      while (i < j && nums[j] % 2 == 0)
        j--;
      swap(nums[i], nums[j]);
    }
  }
};
