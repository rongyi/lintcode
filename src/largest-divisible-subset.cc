// http://www.lintcode.com/zh-cn/problem/largest-divisible-subset
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
   * @param nums a set of distinct positive integers
   * @return the largest subset
   */
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    vector<int> ret;
    if (nums.empty())
      return ret;
    std::sort(nums.begin(), nums.end());
    const int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> index(n, -1);

    int max_index = 0;
    int max_dp = 1;

    for (int i = 0; i < n; i++) {
      for (int j = i - 1; j >= 0; j--) {
        if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
          dp[i] = dp[j] + 1;
          index[i] = j;
        }
      }
      if (max_dp < dp[i]) {
        max_dp = dp[i];
        max_index = i;
      }
    }

    for (int i = max_index; i != -1; i = index[i]) {
      ret.push_back(nums[i]);
    }

    return ret;
  }
};
