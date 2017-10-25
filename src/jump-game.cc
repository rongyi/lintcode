// http://www.lintcode.com/zh-cn/problem/jump-game
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param A: A list of integers
   * @return: The boolean answer
   */
  bool canJump1(vector<int> A) {
    int reach = 0;
    for (int i = 0; i <= reach; i++) {
      reach = std::max(reach, i + A[i]);
      if (reach >= A.size() - 1)
        return true;
    }
    return false;
  }
  // DP思路， f[i] 表示从第0层出发，走到A[i]时剩余的最大步数
  // f[i] = max(f[i - 1], A[i - 1]) - 1
  bool canJump(vector<int> &nums) {
    vector<int> dp(nums.size(), 0);
    for (int i = 1; i < nums.size(); ++i) {
      dp[i] = std::max(dp[i - 1], nums[i - 1]) - 1;
      if (dp[i] < 0) {
        return false;
      }
    }
    return dp[nums.size() - 1] >= 0;
  }
};
