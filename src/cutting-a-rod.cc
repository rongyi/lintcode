// http://www.lintcode.com/zh-cn/problem/cutting-a-rod
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /*
  * @param : the prices
  * @param : the length of rod
  * @return: the max value
  */
  int cutting(vector<int> &prices, int n) {
    std::vector<int> dp(prices.size() + 1);
    dp[0] = 0;
    for (int i = 1; i <= prices.size(); i++) {
      int max = -1;
      for (int j = 0; j < i; j++) {
        max = std::max(max, prices[j] + dp[i - (j + 1)]);
        dp[i] = max;
      }
    }
    return dp[prices.size()];
  }
};
