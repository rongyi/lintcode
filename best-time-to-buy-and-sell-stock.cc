// http://www.lintcode.com/zh-cn/problem/best-time-to-buy-and-sell-stock

class Solution {
public:
  /**
   * @param prices: Given an integer array
   * @return: Maximum profit
   */
  int maxProfit(vector<int> &prices) {
    int ret = 0;
    if (!prices.size())
      return 0;
    if (prices.size() == 1)
      return prices[0];
    int lowest = prices[0];
    for (int i = 1; i < prices.size(); i++) {
      int cur = prices[i];
      ret = max(ret, cur - lowest);
      lowest = min(lowest, cur);
    }
    return ret;
  }
};
