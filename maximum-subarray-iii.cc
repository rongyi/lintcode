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
