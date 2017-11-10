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

  int uniquePaths(int m, int n) {
    // 目的时让第一列和第一行都为1，内层的都会被改写
    vector<vector<int>> dp(m, vector<int>(n, 1));

    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
    return dp[m-1][n-1];
  }
};

int main()
{
  Solution so;
  auto ret = so.uniquePaths(1, 3);
  cout << ret << endl;
  return 0;
}
