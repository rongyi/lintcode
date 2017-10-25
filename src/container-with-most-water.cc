// http://www.lintcode.com/zh-cn/problem/container-with-most-water
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
   * @param heights: a vector of integers
   * @return: an integer
   */
  int maxArea(vector<int> &heights) {
    if (heights.empty())
      return 0;
    int ret = 0;
    int left = 0;
    int right = heights.size() - 1;
    while (left < right) {
      ret = std::max(ret,
                     std::min(heights[left], heights[right]) * (right - left));
      if (heights[left] < heights[right])
        left++;
      else
        right--;
    }

    return ret;
  }
};
