// http://www.lintcode.com/zh-cn/problem/distinct-subsequences
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
public:
  /**
   * @param S, T: Two string.
   * @return: Count the number of distinct subsequences
   */
  int numDistinct(string &S, string &T) {
    const int n = S.size();
    const int m = T.size();
    vector<int> dp(n + 1, 1);

    for (int i = 1; i <= m; i++) {
      int up_left = dp[0];
      dp[0] = 0;
      for (int j = 1; j <= n; j++) {
        int tmp = dp[j];
        dp[j] = dp[j - 1];
        if (S[j - 1] == T[i - 1])
          dp[j] += up_left;
        up_left = tmp;
      }
    }
    return dp[n];
  }
};
