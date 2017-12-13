// http://www.lintcode.com/zh-cn/problem/coin-change-ii

#include <bitset>
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
   * @param amount: a total amount of money amount
   * @param coins: the denomination of each coin
   * @return: the number of combinations that make up the amount
   */
  int change(int amount, vector<int> &coins) {
    vector<vector<int>> ret;
    vector<int> cur;
    dfs(coins, 0, coins.size(), cur, amount, ret);
    for (auto &v : ret) {
      for (auto i : v) {
        cout << i << " ";
      }
      cout << endl;
    }
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
};

int main() {
  Solution so;
  vector<int> test{2, 3, 8};
  auto ret = so.change(8, test);
  cout << ret << endl;
  return 0;
}
