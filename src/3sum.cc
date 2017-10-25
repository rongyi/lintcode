// http://www.lintcode.com/zh-cn/problem/3sum

class Solution {
public:
  /**
   * @param numbers : Give an array numbers of n integer
   * @return : Find all unique triplets in the array which gives the sum of
   * zero.
   */
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> ret;
    if (nums.size() < 3)
      return ret;
    // sort
    sort(nums.begin(), nums.end());

    const int target = 0;

    auto last = nums.end();
    for (auto i = nums.begin(); i < last - 2; ++i) {
      if (i > nums.begin() && *i == *(i - 1))
        continue;
      auto j = i + 1;
      auto k = last - 1;
      while (j < k) {
        if (*i + *j + *k < target) {
          ++j;
          while (*j == *(j - 1) && j < k)
            ++j;
        } else if (*i + *j + *k > target) {
          --k;
          while (*k == (*k + 1) && j < k)
            --k;
        } else {
          ret.push_back({*i, *j, *k});
          ++j;
          --k;
          while (*j == *(j - 1) && j < k)
            ++j;
          while (*k == *(k + 1) && j < k)
            --k;
        }
      }
    }
    return ret;
  }
};
