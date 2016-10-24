// http://www.lintcode.com/zh-cn/problem/best-time-to-buy-and-sell-stock-iv
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
   * @param k: An integer
   * @param prices: Given an integer array
   * @return: Maximum profit
   */
  int maxProfit(int k, vector<int> &prices) {
    if (prices.size() < 2)
      return 0;
    const int m = prices.size();
    if (k >= m)
      return unlimited(prices);

    // dp[i][j]
    // 当前到达第i天，最多可进行j次交易，并且最后一次交易在当天卖出的最好的利润是多少
    vector<vector<int>> local(m, vector<int>(k + 1, 0));
    // 当前到达第i天可以最多进行j次交易，最好的利润是多少
    vector<vector<int>> global(m, vector<int>(k + 1, 0));

    for (int i = 1; i < m; i++) {
      const int diff = prices[i] - prices[i - 1];
      for (int j = 1; j <= k; j++) {
        local[i][j] = std::max(global[i - 1][j - 1], local[i - 1][j] + diff);
        global[i][j] = std::max(global[i - 1][j], local[i][j]);
      }
    }

    return global[m - 1][k];
  }
private:
  int unlimited(const vector<int> &prices) {
    int ret = 0;
    const auto m = prices.size();
    for (unsigned i = 1; i < m; i++) {
      if (prices[i] > prices[i - 1])
        ret += (prices[i] - prices[i - 1]);
    }

    return ret;
  }
};
