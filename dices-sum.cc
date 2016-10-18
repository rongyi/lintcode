// http://www.lintcode.com/zh-cn/problem/dices-sum
#include <vector>
#include <iostream>
#include <string>
#include <cmath>

using std::vector;
using std::cout;
using std::endl;
using std::string;


class Solution {
public:
  /**
   * @param n an integer
   * @return a list of pair<sum, probability>
   */
  vector<std::pair<int, double>> dicesSum(int n) {
    vector<std::pair<int, double>> ret;
    if (n <= 0)
      return ret;
    const double total = std::pow(6, n);
    const int target = 6 * n;
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= target; j++) {
        for (int k = 1; k <= 6; k++) {
          if (j >= k) {
            dp[i][j] += dp[i - 1][j - k];
          }
        }
      }
    }

    for (int i = n; i <= target; i++) {
      int cur_sum = dp[n][i];
      double prob = cur_sum / total;
      ret.push_back(std::make_pair(i, prob));
    }

    return ret;
  }
};

int main()
{
  Solution so;
  auto ret = so.dicesSum(15);
  for (auto p : ret)
    cout << p.first << ": " << p.second << endl;
  return 0;
}
