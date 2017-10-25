// http://www.lintcode.com/zh-cn/problem/search-in-rotated-sorted-array
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
  /**
   * param A : an integer ratated sorted array
   * param target :  an integer to be searched
   * return : an integer
   */
public:
  int search(vector<int> &A, int target) {
    int first = 0;
    int last = A.size();

    while (first != last) {
      const int mid = first + (last - first) / 2;
      if (A[mid] == target)
        return mid;
      if (A[first] <= A[mid]) {
        if (A[first] <= target && target < A[mid])
          last = mid;
        else
          first = mid + 1;
      } else {
        if (A[mid] < target && target <= A[last - 1])
          first = mid + 1;
        else
          last = mid;
      }
    }
    return -1;
  }
};
