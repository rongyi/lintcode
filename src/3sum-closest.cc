// http://www.lintcode.com/zh-cn/problem/3sum-closest

class Solution {
public:
  /**
   * @param numbers: Give an array numbers of n integer
   * @param target: An integer
   * @return: return the sum of the three integers, the sum closest target.
   */
  int threeSumClosest(vector<int> nums, int target) {
    int ret = 0;
    int min_gap = INT_MAX;

    sort(nums.begin(), nums.end());
    for (auto a = nums.begin(); a != prev(nums.end(), 2); ++a) {
      auto b = next(a);
      auto c  = prev(nums.end());
      while (b < c) {
        const int sum = *a + *b + *c;
        const int gap = abs(sum - target);
        if (gap < min_gap) {
          ret = sum;
          min_gap = gap;
        }
        if (sum < target)
          ++b;
        else
          --c;

      }
    }
    return ret;
  }
};
