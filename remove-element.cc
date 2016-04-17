// http://www.lintcode.com/zh-cn/problem/remove-element

class Solution {
public:
  /**
   *@param A: A list of integers
   *@param elem: An integer
   *@return: The new length after remove
   */
  int removeElement(vector<int> &A, int elem) {
    int index = 0;
    for (int i = 0; i < A.size(); i++) {
      if (A[i] != elem)
        A[index++] = A[i];
    }
    return index;
  }
};
