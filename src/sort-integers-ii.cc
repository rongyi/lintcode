// http://www.lintcode.com/zh-cn/problem/sort-integers-ii
#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param A an integer array
   * @return void
   */
  void sortIntegers2(vector<int>& A) {
    if (A.empty())
      return;
    quicksort(A, 0, A.size());
  }
  void quicksort(vector<int> &v, int begin, int end) {
    if (end - begin <= 1)
      return;
    int pivot = v[end - 1];
    int less_end = begin;
    for (int i = begin; i < end - 1; i++) {
      if (v[i] < pivot)
        std::swap(v[i], v[less_end++]);
    }

    // final position
    std::swap(v[end - 1], v[less_end]);
    quicksort(v, begin, less_end);
    quicksort(v, less_end + 1, end);
  }
};

int main(int argc, char *argv[])
{
  vector<int> test{1, 2, 3, 9, 4, 5};
  Solution so;
  so.sortIntegers2(test);
  for (auto i : test)
    cout << i << " ";
  cout << endl;
  return 0;
}
