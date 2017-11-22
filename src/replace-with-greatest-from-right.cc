// http://www.lintcode.com/zh-cn/problem/replace-with-greatest-from-right
#include <vector>
#include <iostream>
#include <string>
#include <bitset>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /*
  * @param : An array of integers.
  * @return: nothing
  */
  void arrayReplaceWithGreatestFromRight(vector<int> &nums) {
    const int n = nums.size();
    if (n == 1) {
      nums[0] = -1;
      return;
    }

    int right_max = nums[n - 1];
    for (int i = n - 2; i >= 0; --i) {
      auto tmp = nums[i];
      nums[i] = right_max;
      right_max = std::max(right_max, tmp);
    }
    nums[n - 1] = -1;
  }
};
