// http://www.lintcode.com/zh-cn/problem/longest-increasing-subsequence
#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;


class Solution {
public:
  /**
   * @param nums: The integer array
   * @return: The length of LIS (longest increasing subsequence)
   */
  int longestIncreasingSubsequence(vector<int> nums) {
    if (nums.empty())
      return 0;

    // 定义状态f[i]为第i个元素为终点的最长递增子序列的长度，那么状态转移方程是
    // f[j] = max{f[i], 0 <= i < j && f[i] < f[j]} + 1
    vector<int> dp(nums.size(), 0);
    int ret = 0;

    for (int i = 0; i < nums.size(); i++) {
      dp[i] = 1;
      for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i]) {
          dp[i] = std::max(dp[i], dp[j] + 1);
        }
      }
      if (dp[i] > ret)
        ret = dp[i];
    }

    return ret;
  }
};
