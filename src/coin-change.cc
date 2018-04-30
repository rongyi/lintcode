// http://www.lintcode.com/zh-cn/problem/coin-change
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
   * @param coins: a list of integer
   * @param amount: a total amount of money amount
   * @return: the fewest number of coins that you need to make up
   */
  int coinChange(vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for (int i = 1; i <= amount; ++i) {
      for (int j = 0; j < coins.size(); ++j) {
        if (coins[j] <= i) {
          dp[i] = std::min(dp[i], dp[i - coins[j]] + 1);
        }
      }
    }

    return dp[amount] > amount ? -1 : dp[amount];
  }
};
