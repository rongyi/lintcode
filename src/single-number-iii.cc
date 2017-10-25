// http://www.lintcode.com/zh-cn/problem/single-number-iii

#include <vector>
using std::vector;

class Solution {
public:
  /**
   * @param A : An integer array
   * @return : Two integers
   */
  vector<int> singleNumberIII(vector<int> &A) {
    const int n = A.size();
    if (n < 3)
      return A;
    int pivot = A[0];
    for (int i = 1; i < n; ++i) {
      pivot ^= A[i];
    }
    int pos = find_first_bit_of1(pivot);
    int num1 = 0;
    int num2 = 0;
    for (int i = 0; i < n; ++i) {
      if (is_pos_1(A[i], pos)) {
        num1 ^= A[i];
      } else {
        num2 ^= A[i];
      }
    }
    vector<int> ret;
    ret.push_back(num1);
    ret.push_back(num2);

    return ret;
  }

private:
  int find_first_bit_of1(int n) {
    int ret = 0;
    while ((n & 0x1) == 0) {
      ++ret;
      n >>= 1;
    }
    return ret;
  }

  bool is_pos_1(int n, int pos) { return ((n >> pos) & 0x1) == 1; }
};
