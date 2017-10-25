// http://www.lintcode.com/zh-cn/problem/best-time-to-buy-and-sell-stock-ii
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
   * @param prices: Given an integer array
   * @return: Maximum profit
   */
  int maxProfit(vector<int> &prices) {
    if (prices.size() == 0)
      return 0;
    int profit = 0;
    for (int i = 0; i < prices.size() - 1; i++) {
      if (prices[i] < prices[i + 1]) {
        profit += prices[i + 1] - prices[i];
      }
    }

    return profit;
  }
};
