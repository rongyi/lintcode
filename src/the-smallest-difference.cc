// http://www.lintcode.com/zh-cn/problem/the-smallest-difference
#include <algorithm>
#include <climits>
#include <vector>
using std::vector;

class Solution {
public:
  /**
   * @param A, B: Two integer arrays.
   * @return: Their smallest difference.
   */
  int smallestDifference(vector<int> &A, vector<int> &B) {
    if (A.empty() || B.empty())
      return -1;
    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());
    int min = INT_MAX;
    for (int i = 0, j = 0; i < A.size() && j < B.size();) {
      int sub = std::abs(A[i] - B[j]);
      min = std::min(sub, min);
      if (A[i] == B[j]) {
        return 0;
      } else if (A[i] > B[j]) {
        j++;
      } else if (A[i] < B[j]) {
        i++;
      }
    }
    return min;
  }
};
