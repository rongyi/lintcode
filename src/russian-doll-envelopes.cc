// http://www.lintcode.com/zh-cn/problem/russian-doll-envelopes
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
        if (envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second) {
          dp[i] = std::max(dp[i], dp[j] + 1);
        }
      } // end for j
      ret = std::max(ret, dp[i]);
    } // end for i
    return ret;
  }

  int maxEnvelopes(vector<pair<int, int>> &envelopes) {

  }
};
