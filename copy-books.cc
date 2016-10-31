// http://www.lintcode.com/zh-cn/problem/copy-books
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
   * @param pages: a vector of integers
   * @param k: an integer
   * @return: an integer
   */
  int copyBooks(vector<int> &books, int k) {
    if (books.empty() || k == 0)
      return 0;
    if (k > books.size())
      k = books.size();

    const int m = books.size();

    // dp[i][j] i people copy j books
    vector<vector<int>> dp(k, vector<int>(m, 0));
    vector<int> aux_books(m, 0);

    aux_books[0] = books[0];
    dp[0][0] = books[0];
    for (unsigned i = 1; i < books.size(); i++) {
      aux_books[i] = aux_books[i - 1] + books[i];
      dp[0][i] = aux_books[i];
    }
    for (int i = 1; i < k; i++) {
      for (int j = i; j < m; j++) {
        int cur_min = std::numeric_limits<int>::max();
        for (int l = i; l <= j; l++) {
          cur_min = std::min(cur_min,
                             std::max(dp[i - 1][l - 1],
                                      aux_books[j] - aux_books[l - 1]));
          dp[i][j] = cur_min;
        }
      }
    }

    return dp[k - 1][m - 1];
  }
};
