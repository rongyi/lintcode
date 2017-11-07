// http://www.lintcode.com/zh-cn/problem/minimum-partition
#include <iostream>
#include <string>
#include <unordered_map>
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
  int findMin(vector<int> &nums) {
    unordered_map<string, int> aux;
    return rec(nums, nums.size() - 1, 0, 0, aux);
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
