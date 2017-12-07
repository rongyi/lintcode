// http://www.lintcode.com/zh-cn/problem/candy/

#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
  /**
   * @param ratings Children's ratings
   * @return the minimum candies you must give
   */
  int candy(vector<int> &ratings) {
    const int n = ratings.size();
    vector<int> increment(n);
    // 和积水的那题差不多就是要扫描然后增加
    for (int i = 1, inc = 1; i < n; i++) {
      // 遇到权重大的就一直涨，否则就把基数“落到”最小
      if (ratings[i] > ratings[i - 1]) {
        increment[i] = inc++;
      } else {
        inc = 1;
      }
    }
    for (int i = n - 2, inc = 1; i >= 0; --i) {
      if (ratings[i] > ratings[i + 1]) {
        increment[i] = std::max(inc++, increment[i]);
      } else {
        inc = 1;
      }
    }
    return std::accumulate(&increment[0], &increment[0] + n, n);
  }
};
