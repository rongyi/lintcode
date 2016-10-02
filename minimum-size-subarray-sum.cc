// http://www.lintcode.com/zh-cn/problem/minimum-size-subarray-sum
#include <vector>
#include <algorithm>
using std::vector;


class Solution {
public:
  /**
   * @param nums: a vector of integers
   * @param s: an integer
   * @return: an integer representing the minimum size of subarray
   */
  int minimumSize(vector<int> &nums, int s) {
    int ret = std::numeric_limits<int>::max();
    int sum = 0;
    int left = 0;
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
      if (sum >= s) {
        while (left <= i && sum >= s) {
          ret = std::min(ret, i - left + 1);
          sum -= nums[left++];
        }
      }
    }

    return ret == std::numeric_limits<int>::max() ? -1 : ret;
  }
};
