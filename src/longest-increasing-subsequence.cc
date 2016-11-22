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

    vector<int> h_lst(nums.size(), 0);
    int ret = 0;

    for (int i = 0; i < nums.size(); i++) {
      h_lst[i] = 1;
      for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i]) {
          h_lst[i] = std::max(h_lst[i], h_lst[j] + 1);
        }
      }
      if (h_lst[i] > ret)
        ret = h_lst[i];
    }

    return ret;
  }
};
