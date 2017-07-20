// http://www.lintcode.com/zh-cn/problem/sliding-window-median
#include <vector>
#include <iostream>
#include <string>
#include <set>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param nums: A list of integers.
   * @return: The median of the element inside the window at each moving
   */
  vector<int> medianSlidingWindow(vector<int> &nums, int k) {
    vector<int> ret;
    std::multiset<int> small;
    std::multiset<int> large;

    for (int i = 0; i < nums.size(); ++i) {
      if (i >= k) {
        if (small.count(nums[i - k])) {
          small.erase(small.find(nums[i - k]));
        } else if (large.count(nums[i - k])) {
          large.erase(large.find(nums[i - k]));
        }
      }

      if (small.size() <= large.size()) {
        if (large.empty() || nums[i] <= *large.begin()) {
          small.insert(nums[i]);
        } else {
          small.insert(*large.begin());
          large.erase(large.begin());
          large.insert(nums[i]);
        }
      } else {
        if (nums[i] >= *small.rbegin()) {
          large.insert(nums[i]);
        } else {
          large.insert(*small.rbegin());
          small.erase(--small.end());
          small.insert(nums[i]);
        }
      }

      if (i >= (k - 1)) {
        ret.push_back(*small.rbegin());
      }
    } // end for

    return ret;
  }
};
