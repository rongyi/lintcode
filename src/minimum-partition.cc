// http://www.lintcode.com/zh-cn/problem/minimum-partition
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <limits>

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
    aux_.clear();

    int sum = 0;
    const auto n = nums.size();
    for (auto i : nums) {
      sum += i;
    }

    // Initialize first column as true. 0 sum is possible
    // with all elements.
    for (int i = 0; i <= n; i++) {
      set(i, 0, true);
    }
    // Initialize top row, except dp[0][0], as false. With
    // 0 elements, no other sum except 0 is possible
    for (int i = 1; i <= sum; i++) {
      set(0, 1, false);
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= sum; j++) {
        auto exc = get(i - 1, j);
        if (exc) {
          set(i, j, true);
        } else { // include current
          auto inc = get(i - 1, j - nums[i - 1]);
          // this is the last change we set it anyway
          set(i, j, inc);
        }
      }
    }

    int diff = std::numeric_limits<int>::min();

    for (int j = sum / 2; j >= 0; j--) {
      if (get(n, j)) {
        diff = sum - 2 * j;
        break;
      }
    }
    return diff;
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

  string key(int i, int j) {
    return std::to_string(i) + ":" + std::to_string(j);
  }

  bool get(int i, int j) {
    auto k = key(i, j);
    if (aux_.find(k) == aux_.end()) {
      return false;
    }

    return aux_[k];
  }

  void set(int i, int j, bool value) {
    auto k = key(i, j);
    aux_[k] = value;
  }

private:
  // dp[n+1][sum+1] = {1 if some subset from 1st to i'th has a sum
  //                    equal to j
  //                    0 otherwise}

  //  i ranges from {1..n}
  //  j ranges from {0..(sum of all elements)}
  unordered_map<string, bool> aux_;
};

int main()
{
  vector<int> nums{1, 6, 11, 5};
  Solution so;
  auto ret = so.findMin(nums);
  cout << ret << endl;
  return 0;
}
