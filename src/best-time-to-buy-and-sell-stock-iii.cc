// http://www.lintcode.com/zh-cn/problem/best-time-to-buy-and-sell-stock-iii
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
   * @param prices: Given an integer array
   * @return: Maximum profit
   */
  int maxProfit(vector<int> &prices) {
    if (prices.empty())
      return 0;
    int ret = 0;
    const int m = prices.size();
    vector<int> left(m, 0);
    vector<int> right(m, 0);

    // left
    int min = prices[0];
    for (int i = 1; i < m; i++) {
      left[i] = std::max(left[i - 1], prices[i] - min);
      min = std::min(min, prices[i]);
    }

    // right
    right[m - 1] = 0;
    int max = prices[m - 1];
    for (int i = m - 2; i >= 0; --i) {
      right[i] = std::max(right[i + 1], max - prices[i]);
      max = std::max(max, prices[i]);
    }

    for (int i = 0; i < m; i++) {
      ret = std::max(ret, left[i] + right[i]);
    }

    return ret;
  }
};
