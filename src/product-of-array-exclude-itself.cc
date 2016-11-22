// http://www.lintcode.com/zh-cn/problem/product-of-array-exclude-itself
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
   * @param A: Given an integers array A
   * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
   */
  vector<long long> productExcludeItself(vector<int> &nums) {
    vector<long long> ret;
    if (nums.empty())
      return ret;
    if (nums.size() == 1) {
      ret.push_back(1);
      return ret;
    }
    const int m = nums.size();
    vector<long long> left(m, 0);
    vector<long long> right(m, 0);
    // left
    left[0] = 1;
    for (int i = 1; i < m; i++) {
      left[i] = left[i - 1] * nums[i - 1];
    }
    // right
    right[m - 1] = 1;
    for (int i = m - 2; i >= 0; --i) {
      right[i] = right[i + 1] * nums[i + 1];
    }
    for (int i = 0; i < m; i++) {
      ret.push_back(left[i] * right[i]);
    }

    return ret;
  }
};
