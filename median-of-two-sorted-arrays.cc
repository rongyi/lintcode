// http://www.lintcode.com/zh-cn/problem/median-of-two-sorted-arrays
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param A: An integer array.
   * @param B: An integer array.
   * @return: a double whose format is *.5 or *.0
   */
  double findMedianSortedArrays(vector<int> A, vector<int> B) {
    const int m = A.size();
    const int n = B.size();
    int total = m + n;
    if (A.empty() && B.empty())
      return 0.0;

    if (total & 0x1) {
      return doFind(A.begin(), A.end(), B.begin(), B.end(), total / 2 + 1);
    } else {
      return (doFind(A.begin(), A.end(), B.begin(), B.end(), total / 2) +
              doFind(A.begin(), A.end(), B.begin(), B.end(), total / 2 + 1)) / 2.0;
    }
  }
private:
  using Iter = vector<int>::const_iterator;

  int doFind(Iter beginA, Iter endA, Iter beginB, Iter endB,
             int k) {
    const int m = std::distance(beginA, endA);
    const int n = std::distance(beginB, endB);
    // make m is *always* smaller or equal than n
    if (m > n)
      return doFind(beginB, endB, beginA, endA, k);
    if (m == 0)
      return *(beginB + k - 1);
    if (k == 1)
      return std::min(*beginA, *beginB);

    int ia = std::min(k / 2, m);
    int ib = k - ia;

    if (*(beginA + ia - 1) < *(beginB + ib - 1))
      return doFind(beginA + ia, endA, beginB, endB, k - ia);
    else if (*(beginA + ia - 1) > *(beginB + ib - 1))
      return doFind(beginA, endA, beginB + ib, endB, k - ib);
    else
      return *(beginA + ia - 1);
  }
};

int main()
{
  Solution so;
  vector<int> test1{2};
  vector<int> test2{};
  auto ret = so.findMedianSortedArrays(test1, test2);
  cout << ret << endl;
  return 0;
}
