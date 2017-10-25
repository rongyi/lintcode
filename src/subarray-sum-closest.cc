// http://www.lintcode.com/zh-cn/problem/subarray-sum-closest
#include <algorithm>
#include <cctype>
#include <climits>
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
   * brute force version will exceed the time limit
   * @param nums: A list of integers
   * @return: A list of integers includes the index of the first number
   *          and the index of the last number
   */
  // vector<int> subarraySumClosest(vector<int> nums){
  //   vector<int> ret;
  //   int cur_sum = 0;
  //   int cur_start = 0;
  //   int most_to_zero = INT_MAX;

  //   int start = 0;
  //   int end = 0;

  //   const int n = nums.size();
  //   for (int i = 0; i < n - 1; i++) {
  //     cur_start = i;
  //     cur_sum = nums[i];
  //     // including subarray contain only one element
  //     if (std::abs(cur_sum) < most_to_zero) {
  //       most_to_zero = std::abs(cur_sum);
  //       start = cur_start;
  //       end = cur_start;
  //     }

  //     for (int j = i + 1; j < n; j++) {
  //       cur_sum += nums[j];
  //       if (std::abs(cur_sum) < most_to_zero) {
  //         most_to_zero = std::abs(cur_sum);
  //         start = cur_start;
  //         end = j;
  //       }
  //     }
  //   }
  //   ret.push_back(start);
  //   ret.push_back(end);

  //   return ret;
  // }

  vector<int> subarraySumClosest(vector<int> nums) {
    vector<std::pair<int, int>> sum_lst;
    vector<int> ret;

    int sum = 0;
    sum_lst.push_back(std::make_pair(sum, -1));
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
      sum_lst.push_back(std::make_pair(sum, i));
    }
    std::sort(sum_lst.begin(), sum_lst.end());

    int start;
    int end;

    int diff = INT_MAX;
    for (int i = 1; i < sum_lst.size(); i++) {
      if (std::abs(sum_lst[i].first - sum_lst[i - 1].first) <= diff) {
        diff = std::abs(sum_lst[i].first - sum_lst[i - 1].first);
        start = std::min(sum_lst[i].second, sum_lst[i - 1].second) + 1;
        end = std::max(sum_lst[i].second, sum_lst[i - 1].second);
      }
    }

    ret.push_back(start);
    ret.push_back(end);
    return ret;
  }
};

int main() {
  Solution so;
  vector<int> test{-3, 1, 1, -3, 5};
  auto ret = so.subarraySumClosest(test);
  for (auto i : ret)
    cout << i << endl;

  return 0;
}
