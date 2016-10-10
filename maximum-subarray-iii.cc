// http://www.lintcode.com/zh-cn/problem/maximum-subarray-iii
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
   * @param nums: A list of integers
   * @param k: An integer denote to find k non-overlapping subarrays
   * @return: An integer denote the sum of max k non-overlapping subarrays
    local[i][k]表示前i个元素取k个子数组并且*必须*包含第i个元素的最大和。
    global[i][k]表示前i个元素取k个子数组不一定包含第i个元素的最大和。
    local[i][k]的状态函数：
        max(global[i-1][k-1], local[i-1][k]) + nums[i-1]
    有两种情况，第一种是第i个元素自己组成一个子数组，则要在前i－1个元素中找k－1个子数组，第二种情况是第i个元素属于前一个元素的子数组，因此要在i－1个元素中找k个子数组（并且必须包含第i－1个元素，这样第i个元素才能合并到最后一个子数组中），取两种情况里面大的那个。
    global[i][k]的状态函数：
        max(global[i-1][k]，local[i][k])
    有两种情况，第一种是不包含第i个元素，所以要在前i－1个元素中找k个子数组，第二种情况为包含第i个元素，在i个元素中找k个子数组且必须包含第i个元素，取两种情况里面大的那个。
   */
  int maxSubArray(vector<int> nums, int k) {
    const int n = nums.size();
    if (n < k)
      return 0;
    vector<vector<int>> global_max(n + 1, vector<int>(k + 1, 0));
    for (int j = 1; j <= k; j++) {
      int local_max = std::numeric_limits<int>::min();
      for (int i = j - 1; i < n; i++) {
        local_max = std::max(local_max, global_max[i][j - 1]) + nums[i];

        if (i == j - 1) {
          global_max[i + 1][j] = local_max;
        } else {
          global_max[i + 1][j] = std::max(global_max[i][j], local_max);
        }
      }
    }
    return global_max[n][k];
  }
};
