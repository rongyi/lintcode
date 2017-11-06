// http://www.lintcode.com/zh-cn/problem/minimum-partition
#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /*
  * @param : the given array
  * @return: the minimum difference between their sums
  */
  int findMinTLE(vector<int> &nums) {
    return rec(nums, nums.size() - 1, 0, 0);
  }
private:
  int rec(vector<int> &nums, int n, int s1, int s2) {
    if (n < 0) {
      return ::abs(s1 - s2);
    }
    int inc = rec(nums, n - 1, s1 + nums[n], s2);

    int exc = rec(nums, n - 1, s1, s2 + nums[n]);

    return std::min(inc, exc);
  }
};
