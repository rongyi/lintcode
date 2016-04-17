// http://www.lintcode.com/zh-cn/problem/first-missing-positive

class Solution {
public:
  /**
   * @param A: a vector of integers
   * @return: an integer
   */
  int firstMissingPositive(vector<int> A) {
    bucket_sort(A);

    const int n = A.size();
    for (int i = 0; i < n; i++) {
      if (A[i] != (i + 1))
        return i + 1;
    }
    return n + 1;
  }
private:
  void bucket_sort(vector<int> &A) {
    const int n = A.size();
    for (int i = 0; i < n; i++) {
      while (A[i] != i + 1) {
        if (A[i] <= 0 || A[i] > n || A[i] == A[A[i] - 1])
          break;
        swap(A[i], A[A[i] - 1]);
      }
    }
  }
};
