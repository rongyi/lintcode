// http://www.lintcode.com/zh-cn/problem/intersection-of-two-arrays-ii
#include <vector>
#include <map>

using std::vector;
using std::map;

class Solution {
public:
  /**
   * @param nums1 an integer array
   * @param nums2 an integer array
   * @return an integer array
   */
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ret;
    map<int, int> count1;
    map<int, int> count2;
    for (auto i :nums1) {
      if (count1.find(i) == count1.end()) {
        count1[i] = 1;
      } else {
        count1[i]++;
      }
    }
    for (auto i : nums2) {
      if (count2.find(i) == count2.end()) {
        count2[i] = 1;
      } else {
        count2[i]++;
      }
    }

    for (auto iter = count1.begin(); iter != count1.end(); iter++) {
      if (count2.find(iter->first) != count2.end()) {
        int round = std::min(iter->second, count2[iter->first]);
        for (int i = 0; i < round; i++) {
          ret.push_back(iter->first);
        }
      }
    }

    return ret;
  }
};
