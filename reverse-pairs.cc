// http://www.lintcode.com/zh-cn/problem/reverse-pairs
#include <vector>
#include <algorithm>
using std::vector;
using std::sort;

class Solution {
public:
  /**
   * @param A an array
   * @return total of reverse pairs
   */
  // long long reversePairs(vector<int>& A) {
  //   long long ret = 0;
  //   const unsigned s = A.size();
  //   for (unsigned i = 0; i < s; i++) {
  //     for (unsigned j = i + 1; j < s; j++) {
  //       if (A[i] > A[j]) {
  //         ret++;
  //       }
  //     }
  //   }

  //   return ret;
  // }
  long long reversePairs(vector<int>& A) {
    // Get the place (position in the ascending order) of each number.
    vector<int> sorted_A(A), places(A.size());
    sort(sorted_A.begin(), sorted_A.end());
    for (int i = 0; i < A.size(); ++i) {
      places[i] =
        lower_bound(sorted_A.begin(), sorted_A.end(), A[i]) -
        sorted_A.begin();
    }
    // Count the smaller elements after the number.
    long long count = 0;
    vector<int> bit(A.size() + 1);
    for (int i = A.size() - 1; i >= 0; --i) {
      count += query(bit, places[i]);
      add(bit, places[i] + 1, 1);
    }
    return count;
  }

private:
  void add(vector<int>& bit, int i, int val) {
    for (; i < bit.size(); i += lower_bit(i)) {
      bit[i] += val;
    }
  }

  int query(const vector<int>& bit, int i) {
    int sum = 0;
    for (; i > 0; i -= lower_bit(i)) {
      sum += bit[i];
    }
    return sum;
  }

  int lower_bit(int i) {
    return i & -i;
  }
};
