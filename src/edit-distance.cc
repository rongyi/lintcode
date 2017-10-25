// http://www.lintcode.com/zh-cn/problem/edit-distance
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param word1 & word2: Two string.
   * @return: The minimum number of steps.

   https://www.youtube.com/watch?v=We3YDTzNXEk
   */
  int minDistance(string word1, string word2) {
    if (word1.empty())
      return word2.length();
    if (word2.empty())
      return word1.length();

    const int m = word1.length();
    const int n = word2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m + 1; i++) {
      for (int j = 0; j < n + 1; j++) {
        if (i == 0) {
          dp[i][j] = j;
        } else if (j == 0) {
          dp[i][j] = i;
        } else {
          if (word1[i - 1] == word2[j - 1]) {
            dp[i][j] = dp[i - 1][j - 1];
          } else {
            /*
                        |
                        |
              ----------+---------------
                        |
                        |                        minums of 3 neighbour and plus
              1
             */
            dp[i][j] = std::min(std::min(dp[i - 1][j - 1], dp[i][j - 1]),
                                dp[i - 1][j]) +
                       1;
          }
        }
      }
    }

    return dp[m][n];
  }
};
