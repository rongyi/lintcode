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
    const int n = coins.size();
    // [i][j] ==> sum to i using j coins
    vector<vector<int>> dp(amount + 1, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
      dp[0][i] = 1;
    }

    for (int i = 1; i <= amount; ++i) {
      for (int j = 0; j < n; j++) {
        // 对于当前这个硬币可取可不取
        // 取当前节点
        int x = (i - coins[j] >= 0) ? dp[i - coins[j]][j] : 0;
        // 不取当前节点
        int y = (j >= 1) ? dp[i][j - 1] : 0;
        dp[i][j]= x + y;
      }
    }
    return dp[amount][n - 1];
  }
};

int main() {
  Solution so;
  vector<int> test{2, 3, 8};
  auto ret = so.change(8, test);
  cout << ret << endl;
  return 0;
}
