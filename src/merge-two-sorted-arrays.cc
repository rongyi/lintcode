// http://www.lintcode.com/zh-cn/problem/merge-two-sorted-arrays
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
  /**
   * @param A and B: sorted integer array A and B.
   * @return: A new sorted integer array
   */
  vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
    vector<int> ret;
    const int m = A.size();
    const int n = B.size();
    int ai = 0;
    int bi = 0;
    for (; ai < m && bi < n;) {
      if (A[ai] < B[bi]) {
        ret.push_back(A[ai++]);
      } else {
        ret.push_back(B[bi++]);
      }
    }
    if (ai < m) {
      for (int i = ai; i < m; i++) {
        ret.push_back(A[ai++]);
      }
    }
    if (bi < n) {
      for (int i = bi; i < n; i++) {
        ret.push_back(B[bi++]);
      }
    }
    return ret;
  }
};
