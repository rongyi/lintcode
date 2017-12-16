// http://www.lintcode.com/zh-cn/problem/coin-change-ii

#include <bitset>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param amount: a total amount of money amount
   * @param coins: the denomination of each coin
   * @return: the number of combinations that make up the amount
   */
  int changeTLE(int amount, vector<int> &coins) {
    vector<vector<int>> ret;
    vector<int> cur;
    dfs(coins, 0, coins.size(), cur, amount, ret);
    return ret.size();
  }
  void dfs(const vector<int> &coins, int i, const int n, vector<int> &cur,
           int sum, vector<vector<int>> &ret) {
    if (sum == 0) {
      ret.push_back(cur);
      return;
    }
    if (i >= n) {
      return;
    }
    if (sum < 0) {
      return;
    }
    cur.push_back(coins[i]);
    dfs(coins, i, n, cur, sum - coins[i], ret);
    cur.pop_back();
    dfs(coins, i + 1, n, cur, sum, ret);
  }

  int change(int amount, vector<int> &coins) {
    const int m = coins.size();
    const int n = amount;
    //  Include the coin: reduce the amount by coin value and use the sub
    //  problem solution (amount-v[i]).
    // Exclude the coin: solution for the same amount without considering
    // that coin.

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // sum is 0, empty set
    for (int i = 0; i <= m; ++i) {
      dp[i][0] = 1;
    }
    // solution[coins+1][amount+1]
    // 1. 0 if i=0
    // 2. 1 if j=0
    // 3. solution[i — 1][j] + solution[i][j — v[i — 1]]  if(coin[i]<=j)
    // 4. solution[i — 1][j]; if(coin[i]>j)
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (coins[i - 1] <= j) {
          dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }
    return dp[m][n];
  }
};

int main() {
  Solution so;
  vector<int> test{2, 3, 8};
  auto ret = so.change(8, test);
  cout << ret << endl;
  return 0;
}
