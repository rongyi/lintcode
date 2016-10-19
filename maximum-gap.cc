// http://www.lintcode.com/zh-cn/problem/maximum-gap
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param nums: a vector of integers
   * @return: the maximum difference
   */
  int maximumGapBruteForce(vector<int> &nums) {
    if (nums.size() < 2)
      return 0;
    std::sort(nums.begin(), nums.end());
    int ret = std::numeric_limits<int>::min();
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] - nums[i - 1] > ret)
        ret = nums[i] - nums[i - 1];
    }

    return ret;
  }

  int maximumGap(vector<int> &nums) {
    if (nums.size() < 2)
      return 0;
    int min_num = *std::min_element(std::begin(nums), std::end(nums));
    int max_num = *std::max_element(std::begin(nums), std::end(nums));

    const int len = (max_num - min_num) / nums.size() + 1;
    // 0 for min, 1 for max
    vector<vector<int>> buckets((max_num - min_num) / len + 1);

    for (auto i : nums) {
      int cur_bucket = (i - min_num) / len;
      if (buckets[cur_bucket].empty()) {
        buckets[cur_bucket].reserve(2);
        buckets[cur_bucket].push_back(i);
        buckets[cur_bucket].push_back(i);
      } else {
        buckets[cur_bucket][0] = std::min(buckets[cur_bucket][0], i);
        buckets[cur_bucket][1] = std::max(buckets[cur_bucket][1], i);
      }
    }
    int ret = 0;
    int prev = 0;
    for (int i = 1; i < buckets.size(); i++) {
      if (buckets[i].empty())
        continue;
      ret = std::max(ret, buckets[i][0] - buckets[prev][1]);
      prev = i;
    }
    return ret;
  }
};

int main()
{
  Solution so;
  vector<int> test{3,2,1,4,3};
  auto ret = so.maximumGapBruteForce(test);
  cout << ret << endl;
  return 0;
}
