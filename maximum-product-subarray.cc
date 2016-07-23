// http://www.lintcode.com/zh-cn/problem/maximum-product-subarray
#include <vector>
using std::vector;

class Solution {
public:
  /**
   * @param nums: a vector of integers
   * @return: an integer
   */
  int maxProduct(vector<int>& nums) {
    if (nums.empty())
      return 0;
    int curmin;
    int curmax;
    int max;
    max = nums[0];
    curmin = nums[0];
    curmax = nums[0];
    const int n = nums.size();
    for (int i = 1; i < n; i++) {
      int tmpmax = max3(nums[i], nums[i] * curmax, curmin * nums[i]);
      int tmpmin = min3(nums[i], nums[i] * curmax, curmin * nums[i]);
      curmax = tmpmax;
      curmin = tmpmin;
      max = std::max(max, curmax);
    }
    return max;
  }

private:
  int min3(int a, int b, int c) {
    if (a < b) {
      return std::min(a, c);
    }
    return std::min(b, c);
  }
  int max3(int a, int b, int c) {
    if (a > b) {
      return std::max(a, c);
    }
    return std::max(b, c);
  }
};
