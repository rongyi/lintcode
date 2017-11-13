// http://www.lintcode.com/zh-cn/problem/maximum-difference-in-arrays
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /*
  * @param : an array of arrays
  * @return: return the max distance among arrays
  */
  int maxDiff(vector<vector<int>> &arrs) {
    int ret = 0;
    int min_val = arrs[0].front();
    int max_val = arrs[0].back();
    for (int i = 1; i < arrs.size(); ++i) {
      ret = std::max(ret, ::abs(arrs[i].back() - min_val));
      ret = std::max(ret, ::abs(max_val - arrs[i].front()));
      max_val = std::max(arrs[i].back(), max_val);
      min_val = std::min(arrs[i].front(), min_val);
    }
    return ret;
  }
};
