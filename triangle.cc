// http://www.lintcode.com/zh-cn/problem/triangle
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
   * @param triangle: a list of lists of integers.
   * @return: An integer, minimum path sum.
   */
  int minimumTotal(vector<vector<int> > &triangle) {
    if (triangle.empty())
      return 0;
    if (triangle.size() == 1)
      return triangle[0][0];
    const int m = triangle.size();
    // FIXME: space may waste a little
    vector<vector<int>> dp(m, vector<int>(m, 0));
    dp[0][0] = triangle[0][0];

    for (int cur_level = 1; cur_level < m; cur_level++) {
      const auto cur_vec = triangle[cur_level];

      for (int i = 0; i < cur_vec.size(); i++) {
        if (i == 0) {
          dp[cur_level][i] = cur_vec[i] + dp[cur_level - 1][i];
        } else if (i == cur_vec.size() - 1) {
          dp[cur_level][i] = cur_vec[i] + dp[cur_level - 1][i - 1];
        } else {
          dp[cur_level][i] = std::min(dp[cur_level - 1][i - 1], dp[cur_level - 1][i]) + cur_vec[i];
        }
      }
    }
    auto final_vec = dp[m - 1];
    return *std::min_element(final_vec.begin(), final_vec.end());
  }
};
