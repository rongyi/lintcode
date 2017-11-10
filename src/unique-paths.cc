// http://www.lintcode.com/zh-cn/problem/unique-paths
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
  /**
   * @param n, m: positive integer (1 <= n ,m <= 100)
   * @return an integer
   */
  int uniquePaths2(int m, int n) {
    vector<int> dp(n, 1);
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        dp[j] += dp[j - 1];
      }
    }

    return dp[n - 1];
  }

  // to minic the way used in uniq path II
  int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    dp[1][1] = 1;

    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        // ignore the origin point
        if (i == 1 && j == 1) {
          continue;
        }
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
    return dp[m][n];
  }
};

int main()
{
  Solution so;
  auto ret = so.uniquePaths(1, 3);
  cout << ret << endl;
  return 0;
}
