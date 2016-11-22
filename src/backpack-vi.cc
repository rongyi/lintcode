// http://www.lintcode.com/zh-cn/problem/backpack-vi
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
   * @param nums an integer array and all positive numbers, no duplicates
   * @param target an integer
   * @return an integer
   */
  int backPackVI(vector<int>& nums, int target) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= target; i++) {
      for (auto n :nums) {
        if (n <= i) {
          dp[i] += dp[i - n];
        }
      }
    }

    return dp.back();
  }
};
