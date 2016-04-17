// http://www.lintcode.com/zh-cn/problem/single-number-ii

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
  /**
   * @param A : An integer array
   * @return : An integer
   */
  int singleNumberII(vector<int> &A) {
    vector<int> count;
    count.resize(32);
    fill(count.begin(), count.end(), 0);
    for (int i = 0; i < A.size(); i++) {
      int cur = A[i];
      for (int j = 0; j < 32; j++) {
        if ((0x1 << j) & cur) {
          count[j]++;
          count[j] %= 3;
        }
      }
    }
    int ret = 0;
    for (int i = 0; i < 32; i++) {
      ret |= (count[i] << i);
    }
    return ret;
  }
};
