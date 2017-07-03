// http://www.lintcode.com/zh-cn/problem/guess-number-game-ii
#include <vector>
#include <iostream>
#include <string>
#include <limits>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param n an integer
   * @return how much money you need to have to guarantee a win
   */
  int getMoneyAmount(int n) {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int l = n - 1; l > 0; --l) {
      for (int r = l + 1; r <= n; ++r) {
        dp[l][r] = std::numeric_limits<int>::max();
        for (int i = l; i < r; i++) {
          dp[l][r] = std::min(dp[l][r], i + std::max(dp[l][i - 1], dp[i + 1][r]));
        }
      }
    }

    return dp[1][n];
  }
};
