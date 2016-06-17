// http://www.lintcode.com/zh-cn/problem/intersection-of-two-arrays

#include <vector>
#include <map>
#include <set>
#include <algorithm>
using std::vector;
using std::set;

class Solution {
public:
  /**
   * @param nums1 an integer array
   * @param nums2 an integer array
   * @return an integer array
   */
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ret;
    set<int> set1;
    set<int> set2;

    for (auto i : nums1) {
      set1.insert(i);
    }
    for (auto i : nums2) {
      set2.insert(i);
    }
    std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), std::inserter(ret, ret.begin()));

    return ret;
  }
};
