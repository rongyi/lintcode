// http://www.lintcode.com/zh-cn/problem/permutations-ii
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param nums: A list of integers.
   * @return: A list of unique permutations.
   */
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<vector<int>> ret;
    if (nums.size() == 0)
      return vector<vector<int>>{{}};

    vector<int> cur;
    doPermute(nums, ret, cur, 0);

    return ret;
  }

private:
  void doPermute(vector<int> &nums, vector<vector<int>> &ret, vector<int> &cur,
                 unsigned index) {
    if (index == nums.size()) {
      ret.push_back(cur);
      return;
    }

    std::unordered_set<int> set;
    for (int i = index; i < nums.size(); i++) {
      if (set.find(nums[i]) == set.end()) {
        set.insert(nums[i]);

        std::swap(nums[index], nums[i]);
        cur.push_back(nums[index]);
        doPermute(nums, ret, cur, index + 1);
        cur.pop_back();
        std::swap(nums[index], nums[i]);
      }
    }
  }
};
