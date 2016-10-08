// http://www.lintcode.com/zh-cn/problem/4sum
#include <unordered_map>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::string;

using std::unordered_map;
class Solution {
public:
  /**
   * @param numbers: Give an array numbersbers of n integer
   * @param target: you need to find four elements that's sum of target
   * @return: Find all unique quadruplets in the array which gives the sum of
   *          zero.
   */
  vector<vector<int> > fourSum(vector<int> nums, int target) {
    vector<vector<int> > ret;
    if (nums.size() < 4)
      return ret;
    std::sort(nums.begin(), nums.end());
    unordered_map<int, vector<std::pair<int, int> > > cache;

    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        cache[nums[i] + nums[j]].push_back(std::pair<int, int>(i, j));
      }
    }

    for (int c = 0; c < nums.size(); ++c) {
      for (int d = c + 1; d < nums.size(); ++d) {
        const int key = target - nums[c] - nums[d];
        if (cache.find(key) == cache.end())
          continue;
        const auto &vec = cache[key];
        for (size_t k = 0; k < vec.size(); ++k) {
          if (c <= vec[k].second)
            continue;
          ret.push_back({nums[vec[k].first], nums[vec[k].second], nums[c], nums[d]});
        }
      }
    }

    sort(ret.begin(), ret.end());
    ret.erase(unique(ret.begin(), ret.end()), ret.end());

    return ret;
  }
};
