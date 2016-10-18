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

    const int target = 6 * n;
    vector<vector<long long>> dp(n, vector<long long>(target + 1, 0));

    dp[0][0] = 1;
    for (int i = 1; i <= 6; i++) {
      dp[0][i] = 1;
    }

    for (int i = 1; i < n; i++) {
      for (int j = i; j < i * 6 + 1; j++) {
        for (int k = 1; k <= 6; k++) {
          dp[i][j + k] += dp[i - 1][j];
        }
      }
    }

    double total = 0;
    for (int i = n; i <= target; i++) {
      if (dp[n - 1][i] > 0)
        total += dp[n - 1][i];
    }

    for (int i = n; i <= target; i++) {
      if (dp[n - 1][i] > 0) {
        double cur_sum = (dp[n - 1][i]) + 0.0;
        double prob = cur_sum / total;
        ret.push_back(std::make_pair(i, prob));
      }
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
