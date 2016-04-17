// http://www.lintcode.com/zh-cn/problem/remove-duplicates-from-sorted-array

class Solution {
public:
  /**
   * @param A: a list of integers
   * @return : return an integer
   */
  int removeDuplicates(vector<int> &nums) {
    if (nums.empty())
      return 0;
    int index = 1;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] != nums[index - 1])
        nums[index++] = nums[i];
    }
    return index;

  }
};
