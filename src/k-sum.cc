// http://www.lintcode.com/zh-cn/problem/k-sum
#include <cstring>
#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
  /**
   * @param A: an integer array.
   * @param k: a positive integer (k <= length(A))
   * @param target: a integer
   * @return an integer
   */
  int kSum(vector<int> A, int k, int target) {
    const int n = A.size();
    if (n == 0)
      return 0;
    // f[i][j][t] indicates the number of solutions for selecting j numbers from
    // A[0 … i – 1] with the sum of t.
    //     Transit function:
    // dp[i][j][m] = dp[i - 1][j][m]   // no choose item i
    // if (A[i - 1] <= m) dp[i][j][m] += dp[i - 1][j - 1][m - A[i - 1]]  //
    // choose item i
    int dp[n + 1][k + 1][target + 1];
    // I miss Go
    std::memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= n; i++) {
      dp[i][0][0] = 1;
    }
    for (int i = 1; i < n + 1; i++) {
      for (int j = 1; j <= k && j <= i; j++) {
        for (int t = 1; t <= target; t++) {
          dp[i][j][t] = 0;
          if (A[i - 1] <= t) {
            // with current
            dp[i][j][t] = dp[i - 1][j - 1][t - A[i - 1]];
          }
          // without current
          dp[i][j][t] += dp[i - 1][j][t];
        }
      }
    }

    return dp[n][k][target];
  }
};

int main() {
  Solution so;
  vector<int> test{1, 2, 3, 4};
  auto ret = so.kSum(test, 2, 5);
  std::cout << ret << std::endl;
  return 0;
}
