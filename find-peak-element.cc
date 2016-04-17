// http://www.lintcode.com/zh-cn/problem/find-peak-element

class Solution {
public:
  /**
   * @param A: An integers array.
   * @return: return any of peek positions.
   */
  int findPeak(vector<int> A) {
    if (A.size() <= 1)
      return 0;
    for (int i = 1; i < A.size(); i++) {
      if (A[i] > A[i - 1] && A[i] > A[i + 1])
        return i;
    }
  }
};
