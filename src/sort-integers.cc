// http://www.lintcode.com/zh-cn/problem/sort-integers
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param A an integer array
   * @return void
   * using select sort
   */
  void sortIntegers(vector<int> &A) {
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

int main() {
  vector<int> test{3, 2, 1, 4, 5};
  Solution so;
  so.sortIntegers(test);
  for (auto i : test)
    cout << i << " ";
  cout << endl;
  return 0;
}
