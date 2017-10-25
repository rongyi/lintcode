// http://www.lintcode.com/zh-cn/problem/russian-doll-envelopes
#include <algorithm>
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
   * destructive!!, brute force
   * @param envelopes a number of envelopes with widths and heights
   * @return the maximum number of envelopes
   */
  int maxEnvelopesBruteForce(vector<pair<int, int>> &envelopes) {
    int ret = 0;
    const int n = envelopes.size();

    vector<int> dp(n, 1);
    std::sort(envelopes.begin(), envelopes.end());
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (envelopes[i].first > envelopes[j].first &&
            envelopes[i].second > envelopes[j].second) {
          dp[i] = std::max(dp[i], dp[j] + 1);
        }
      } // end for j
      ret = std::max(ret, dp[i]);
    } // end for i
    return ret;
  }

  int maxEnvelopes(vector<pair<int, int>> &nums) {
    vector<int> dp;
    std::sort(
        nums.begin(), nums.end(),
        [](const std::pair<int, int> &a, const std::pair<int, int> &b) -> bool {
          if (a.first == b.first)
            return a.second > b.second;
          return a.first < b.first;
        });

    for (int i = 0; i < nums.size(); ++i) {
      auto it = std::lower_bound(dp.begin(), dp.end(), nums[i].second);
      if (it == dp.end())
        dp.push_back(nums[i].second);
      else
        *it = nums[i].second;
    }

    return dp.size();
  }
};
