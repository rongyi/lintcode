// http://www.lintcode.com/zh-cn/problem/trapping-rain-water

#include <vector>

using std::vector;

class Solution {
public:
  /**
   * @param heights: a vector of integers
   * @return: a integer
   */
  int trapRainWater(vector<int> &heights) {
    const int n = heights.size();
    auto max_left = vector<int>(n, 0);
    auto max_right = vector<int>(n, 0);

    for (int i = 1; i < n; ++i) {
      max_left[i] = std::max(max_left[i - 1], heights[i - 1]);
    }
    for (int i = n - 2; i >= 0; --i) {
      max_right[i] = std::max(max_right[i + 1], heights[i + 1]);
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
      int height = std::min(max_left[i], max_right[i]);
      if (height > heights[i])
        sum += height - heights[i];
    }

    return sum;
  }
};
