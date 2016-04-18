// http://www.lintcode.com/zh-cn/problem/search-insert-position

class Solution {
  /**
   * param A : an integer sorted array
   * param target :  an integer to be inserted
   * return : an integer
   */
public:
  int searchInsert(vector<int> &A, int target) {
    return lower_bound(A.begin(), A.end(), target) - A.begin();
  }
  template<typename ForwardIterator, typename T>
  ForwardIterator lower_bound(ForwardIterator first,
                              ForwardIterator last, T value) {
    while (first != last) {
      auto mid = next(first, distance(first, last) / 2);

      if (value > *mid)
        first = ++mid;
      else
        last = mid;
    }
    return first;
  }
};
