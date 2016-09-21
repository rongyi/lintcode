// http://www.lintcode.com/zh-cn/problem/burst-balloons
#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param nums a list of integer
   * @return an integer, maximum coins
   */
  int maxCoins(vector<int>& nums) {
    const int n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));

    for (int len = 1; len <= n; ++len) {
      for (int left = 1; left <= n - len + 1; ++left) {
        int right = left + len - 1;

        // dp[i][j]表示打爆区间[i,j]中的所有气球能得到的最多金币
        for (int k = left; k <= right; ++k) {
          dp[left][right] = std::max(dp[left][right],
                                     // 左边炸的最高分 + 右边最高分 + 当前所炸分
                                     nums[left - 1] * nums[k] * nums[right + 1] + dp[left][k - 1] + dp[k + 1][right]);
        }
      }
    }

    return dp[1][n];
  }
};

int main()
{
  Solution so;
  vector<int> test{4, 1, 5, 10};
  auto ret = so.maxCoins(test);
  cout << ret << endl;

  return 0;
}
