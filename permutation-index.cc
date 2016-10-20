// http://www.lintcode.com/zh-cn/problem/permutation-index
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
   * @param A an integer array
   * @return a long integer
   */
  long long permutationIndex(vector<int>& nums) {
    if (nums.empty())
      return 0;

    const int m = nums.size();
    long long ret = 1;
    long long factor = 1;
    for (int i = m - 1; i >= 0; --i) {
      int rank = 0;
      for (int j = i + 1; j < m; ++j) {
        // previous number
        if (nums[j] < nums[i])
          ++rank;
      }

      ret += rank * factor;
      factor *= (nums.size() - i);
    }

    return ret;
  }
};
