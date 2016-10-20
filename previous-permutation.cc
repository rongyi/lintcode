// http://www.lintcode.com/zh-cn/problem/previous-permutation
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
   * @param nums: An array of integers
   * @return: An array of integers that's previous permuation
   */
  vector<int> previousPermuation(vector<int> &nums) {
    if (nums.size() < 2)
      return nums;

    return doPermute(nums);
  }
private:
  vector<int> doPermute(vector<int> &nums) {
    const int m = nums.size();
    int i = m - 1;
    while (i > 0 && nums[i - 1] <= nums[i])
      i--;
    if (i > 0) {
      int j = i - 1;
      for (; j + 1 < m && nums[j + 1] < nums[i - 1]; j++)
        ;
      std::swap(nums[i - 1], nums[j]);
      std::reverse(nums.begin() + i, nums.end());
    } else {
      std::reverse(nums.begin(), nums.end());
    }
    return nums;
  }
};

int main()
{
  Solution so;
  vector<int> test{1, 3, 2};
  auto ret = so.previousPermuation(test);
  for (auto i : ret)
    cout << i << endl;
  return 0;
}
