// http://www.lintcode.com/zh-cn/problem/permutations
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
   * @return: A list of permutations.
   */
  vector<vector<int>> permuteCheating(vector<int> nums) {
    vector<vector<int>> ret{};
    if (nums.size() == 0)
      return vector<vector<int>>{{}};

    sort(nums.begin(), nums.end());

    do {
      ret.push_back(nums);
    } while (next_permutation(nums.begin(), nums.end()));

    return ret;
  }

  vector<vector<int>> permute(vector<int> nums) {
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

    for (int i = index; i < nums.size(); i++) {
      std::swap(nums[index], nums[i]);
      cur.push_back(nums[index]);
      doPermute(nums, ret, cur, index + 1);
      cur.pop_back();
      std::swap(nums[index], nums[i]);
    }
  }
};

int main() {
  Solution so;
  vector<int> test{1, 2, 3};
  auto ret = so.permute(test);
  for (auto vec : ret) {
    for (auto i : vec)
      cout << i << " ";
    cout << endl;
  }
  return 0;
}
