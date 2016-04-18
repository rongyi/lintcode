// http://www.lintcode.com/zh-cn/problem/permutations

class Solution {
public:
  /**
   * @param nums: A list of integers.
   * @return: A list of permutations.
   */
  vector<vector<int> > permute(vector<int> nums) {
    vector<vector<int>> ret;
    if (nums.size() == 0)
      return ret;

    sort(nums.begin(), nums.end());


    do {
      ret.push_back(nums);
    } while (next_permutation(nums.begin(), nums.end()));

    return ret;
  }
};
