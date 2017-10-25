// http://www.lintcode.com/zh-cn/problem/median
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
   * @param nums: A list of integers.
   * @return: An integer denotes the middle number of the array.
   */
  int median(vector<int> &nums) {
    if (nums.empty())
      return 0;
    std::sort(nums.begin(), nums.end());
    const int n = nums.size();
    if (n & 0x1) {
      return nums[n / 2];
    } else {
      return nums[n / 2 - 1];
    }
  }
};

int main() {
  Solution so;
  vector<int> test{7, 9, 4, 5};
  auto ret = so.median(test);
  cout << ret << endl;
  return 0;
}
