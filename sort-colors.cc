// http://www.lintcode.com/zh-cn/problem/sort-colors

class Solution{
public:
  /**
   * @param nums: A list of integer which is 0, 1 or 2
   * @return: nothing
   */
  void sortColors(vector<int> &nums) {
    int red = 0;
    int blue = nums.size() - 1;

    for (int i = 0; i < blue + 1;) {
      if (nums[i] == 0)
        std::swap(nums[i++], nums[red++]);
      else if (nums[i] == 2)
        std::swap(nums[i], nums[blue--]);
      else
        i++;
    }
  }
};
