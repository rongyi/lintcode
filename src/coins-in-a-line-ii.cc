// http://www.lintcode.com/zh-cn/problem/coins-in-a-line-ii
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
   * @param values: a vector of integers
   * @return: a boolean which equals to true if the first player will win
    我们走到i时，有两种选择:
    + 取values[i]
      我们取了values[i],对手的选择有 values[i+1]或者values[i+1] + values[i+2] 剩下的最大总value分别为DP[i+2]或DP[i+3], 对手也是理性的所以要让我们得到最小value
      所以 value1 = values[i] + min(DP[i+2], DP[i+3])
    + 取values[i] + values[i+1]
      我们取了values[i]和values[i+1] 同理 value2 = values[i] + values[i+1] + min(DP[i+3], DP[i+4])
   */
  bool firstWillWin(vector<int> &values) {
    const int n = values.size();
    if (n <= 2)
      return true;
    vector<int> dp(n, 0);
    dp[n - 1] = values[n - 1];
    dp[n - 2] = values[n - 1] + values[n - 2];

    for (int i = n - 3; i >= 0; --i) {
      int val1 = values[i] + std::min(i + 2 < n ? dp[i + 2] : 0, i + 3 < n ? dp[i + 3] : 0);
      int val2 = values[i] + values[i + 1] + std::min(i + 3 < n ? dp[i + 3] : 0, i + 4 < n ? dp[i + 4] : 0);
      dp[i] = std::max(val1, val2);
    }

    int sum = std::accumulate(values.begin(), values.end(), 0);

    return dp[0] > sum - dp[0];
  }
};
