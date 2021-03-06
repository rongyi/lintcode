// http://www.lintcode.com/zh-cn/problem/predict-the-winner
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Solution {
public:
  /**
   * @param nums: nums an array of scores
   * @return: check if player 1 will win
   */
  bool PredictTheWinnerTLE(vector<int> &nums) { return canWin(nums, 0, 0, 1); }
  bool canWin(vector<int> nums, int sum1, int sum2, int player) {
    if (nums.empty()) {
      return sum1 > sum2;
    }
    if (nums.size() == 1) {
      if (player == 1) {
        return nums[0] + sum1 > sum2;
      }
      // player2 can win?
      return sum2 + nums[0] > sum1;
    }
    vector<int> va = vector<int>(nums.begin() + 1, nums.end());
    vector<int> vb = vector<int>(nums.begin(), nums.end() - 1);
    if (player == 1) {
      // we expect palyer 2 will lose
      return !canWin(va, sum1 + nums[0], sum2, 2) ||
             !canWin(vb, sum1 + nums.back(), sum2, 2);
    }

    // player2 also wish player 1 lose
    return !canWin(va, sum1, sum2 + nums[0], 1) ||
           !canWin(vb, sum1, sum2 + nums.back(), 1);
  }
  bool PredictTheWinner(vector<int> &nums) {
    const int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    return canWin2(nums, 0, n - 1, dp) >= 0;
  }

  int canWin2(vector<int> &nums, int s, int e, vector<vector<int>> &dp) {
    if (dp[s][e] == -1) {
      dp[s][e] = (s == e) ? nums[s]
                          : std::max(nums[s] - canWin2(nums, s + 1, e, dp),
                                     nums[e] - canWin2(nums, s, e - 1, dp));
    }
    return dp[s][e];
  }
};
