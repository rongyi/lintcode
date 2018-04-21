// http://www.lintcode.com/zh-cn/problem/window-sum
#include <vector>
#include <iostream>
#include <string>
#include <bitset>
#include <numeric>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param nums: a list of integers.
   * @param k: length of window.
   * @return: the sum of the element inside the window at each moving.
   */
  vector<int> winSum(vector<int> &nums, int k) {
    if (nums.empty()) {
      return vector<int>{};
    }
    auto ret = vector<int>{};
    const int n = nums.size();
    if (k >= n) {
      auto sum = std::accumulate(nums.begin(), nums.end(), 0);
      ret.push_back(sum);
      return ret;
    }
    auto prev_sum = std::accumulate(nums.begin(), std::next(nums.begin(), k), 0);
    ret.push_back(prev_sum);
    for (int i = k; i < n; i++) {
      int tmp = prev_sum + nums[i] - nums[i - k];
      ret.push_back(tmp);
      prev_sum = tmp;
    }
    return ret;
  }
};

int main() {
  Solution so;
  vector<int> test{1,2,7,8,5};
  auto ret = so.winSum(test, 3);
  for (auto i: ret) {
    cout << i << endl;
  }
}
