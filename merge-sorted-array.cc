// http://www.lintcode.com/zh-cn/problem/merge-sorted-array

class Solution {
public:
  /**
   * @param A: sorted integer array A which has m elements,
   *           but size of A is m+n
   * @param B: sorted integer array B which has n elements
   * @return: void
   */
  void mergeSortedArray(int A[], int m, int B[], int n) {
    int icur = m + n - 1;
    int acur = m - 1;
    int bcur = n - 1;
    const int size = m + n;
    int *tmp = new int[size];
    while (acur >= 0 && bcur >= 0) {
      tmp[icur--] = A[acur] > B[bcur] ? A[acur--] : B[bcur--];
    }
    while (acur >= 0) {
      tmp[icur--] = A[acur--];
    }
    while (bcur >= 0) {
      tmp[icur--] = B[bcur--];
    }
    for (int i = 0; i < size; ++i) {
      A[i] = tmp[i];
    }
    delete[] tmp;
  }
};
