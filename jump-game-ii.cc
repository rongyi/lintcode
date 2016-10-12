// http://www.lintcode.com/zh-cn/problem/jump-game-ii
#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param A: A list of lists of integers
   * @return: An integer
   */
  int jump(vector<int> A) {
    int ret = 0;
    int last = 0;
    int cur = 0;
    for (int i = 0; i < A.size(); i++) {
      if (i > last) {
        last = cur;
        ++ret;
      }
      cur = std::max(cur, i + A[i]);
    }

    return ret;
  }
};
