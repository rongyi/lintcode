// http://www.lintcode.com/zh-cn/problem/minimum-partition
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;

class Solution {
public:
  /*
  * @param : the given array
  * @return: the minimum difference between their sums
  */
  int findMinTLE(vector<int> &nums) {
    unordered_map<string, int> aux;
    return rec(nums, nums.size() - 1, 0, 0, aux);
  }

  int findMin(vector<int> &nums) {
    const unsigned n = nums.size();

    int sum_all = 0;
    for (auto num : nums)
      sum_all += num;

    bool is_odd = (sum_all & 1);
    sum_all >>= 1; // half sum
    vector<bool> dp(sum_all + 1, false);

    dp[0] = true;
    for (int i = 0; i < n; ++i)
      for (int j = sum_all; j >= nums[i]; --j)
        dp[j] = dp[j] || dp[j - nums[i]];

    // check for solution closest to half sum
    int result = 0;
    for (int i = sum_all; i > 0; --i) {
      if (dp[i]) {
        result = (sum_all - i) << 1;
        break;
      }
    }

    return is_odd ? result + 1 : result;
  }

private:
  int rec(vector<int> &nums, int n, int s1, int s2,
          unordered_map<string, int> &aux) {
    if (n < 0) {
      return ::abs(s1 - s2);
    }
    string key = std::to_string(n) + "|" + std::to_string(s1);

    if (aux.find(key) == aux.end()) {
      int inc = rec(nums, n - 1, s1 + nums[n], s2, aux);
      int exc = rec(nums, n - 1, s1, s2 + nums[n], aux);

      aux[key] = std::min(inc, exc);
    }

    return aux[key];
  }
};

int main() {
  vector<int> nums{1, 6, 11, 5};
  Solution so;
  auto ret = so.findMin(nums);
  cout << ret << endl;
  return 0;
}
