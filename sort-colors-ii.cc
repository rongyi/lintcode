// http://www.lintcode.com/zh-cn/problem/sort-colors-ii
#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution{
public:
  /**
   * @param colors: A list of integer
   * @param k: An integer
   * @return: nothing
   */
  void sortColors2(vector<int> &colors, int k) {
    sortIntegers(colors);
  }

private:
  // selected sort
  void sortIntegers(vector<int>& A) {
    if (A.empty())
      return;
    const int len = A.size();
    for (int i = 0; i < len; i++) {
      int min = A[i];
      int min_index = i;
      for (int j = i + 1; j < len; j++) {
        if (A[j] < min) {
          min = A[j];
          min_index = j;
        }
      }
      if (min_index != i) {
        std::swap(A[i], A[min_index]);
      }
    }
  }
};
