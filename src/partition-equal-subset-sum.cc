// http://www.lintcode.com/zh-cn/problem/partition-equal-subset-sum
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param nums a non-empty array only positive integers
   * @return return true if can partition or false
   */
  bool canPartition(vector<int>& nums) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if (sum & 0x1)
      return false;
    int target = sum / 2;

    vector<bool> dp(target + 1, false);
    dp[0] = true;
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = target; j >= nums[i]; --j) {
        dp[j] = dp[j] || dp[j - nums[i]];
      }
    }
    return dp.back();
  }
};

int main()
{
  Solution so;
  vector<int> test{1, 5, 11, 5};
  auto ret = so.canPartition(test);
  cout << ret << endl;
  return 0;
}
