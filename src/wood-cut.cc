// http://www.lintcode.com/zh-cn/problem/wood-cut
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
   *@param L: Given n pieces of wood with length L[i]
   *@param k: An integer
   *return: The maximum length of the small pieces.
   */
  int woodCut(vector<int> L, int k) {
    if (L.empty() || k == 0)
      return false;
    int begin = 0;
    // end is the max of vector L
    int end = 0;
    int ret = 0;
    for (int i = 0; i < L.size(); i++) {
      end = std::max(end, L[i]);
    }

    while (begin <= end) {
      const int mid = begin + (end - begin) / 2;
      // can be much bigger
      if (unit_qulify(L, mid, k)) {
        begin = mid + 1;
        ret = mid;
      } else {
        end = mid - 1;
      }
    }
    return ret;
  }

  bool unit_qulify(const vector<int> &l, int unit, int k) {
    if (!unit)
      return false;
    auto ret = 0;
    for (auto i : l) {
      ret += i / unit;
    }

    return ret >= k;
  }
};
