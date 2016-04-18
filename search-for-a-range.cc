// http://www.lintcode.com/zh-cn/problem/search-for-a-range

class Solution {
  /**
   *@param A : an integer sorted array
   *@param target :  an integer to be inserted
   *return : a list of length 2, [index1, index2]
   */
public:
  vector<int> searchRange(vector<int> &A, int target) {
    const int n = A.size();
    if (n == 0)
      return vector<int>{-1, -1};

    const int l = distance(A.begin(), lower_bound(A.begin(), A.end(), target));
    const int u = distance(A.begin(), prev(upper_bound(A.begin(), A.end(), target)));

    if (A[l] != target)
      return vector<int>{-1, -1};
    else
      return vector<int>{l, u};
  }
};
