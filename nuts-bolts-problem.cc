// http://www.lintcode.com/zh-cn/problem/nuts-bolts-problem
#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

/**
 * class Comparator {
 *     public:
 *      int cmp(string a, string b);
 * };
 * You can use compare.cmp(a, b) to compare nuts "a" and bolts "b",
 * if "a" is bigger than "b", it will return 1, else if they are equal,
 * it will return 0, else if "a" is smaller than "b", it will return -1.
 * When "a" is not a nut or "b" is not a bolt, it will return 2, which is not valid.
 */

class Comparator {
public:
  int cmp(string a, string b);
};

class Solution {
public:
  /**
   * @param nuts: a vector of integers
   * @param bolts: a vector of integers
   * @param compare: a instance of Comparator
   * @return: nothing
   Other way of asking this problem is, given a box with locks and keys where one lock
   can be opened by one key in the box. We need to match the pair.
  */
  void sortNutsAndBolts(vector<string> &nuts, vector<string> &bolts, Comparator compare) {
    if (nuts.empty() || nuts.size() != bolts.size())
      return;
    quickSort(nuts, bolts, compare, 0, nuts.size() - 1);
  }
  void quickSort(vector<string> &nuts,
                 vector<string> &bolts,
                 Comparator compare,
                 int start,
                 int end) {
    if (start >= end)
      return;
    int cur_index = partition(nuts, bolts[start], compare, start, end);
    partition(bolts, nuts[cur_index], compare, start, end);

    quickSort(nuts, bolts, compare, start, cur_index - 1);
    quickSort(nuts, bolts, compare, cur_index + 1, end);
  }
  int partition(vector<string> &norb, string pivot, Comparator compare, int start, int end) {
    int pivot_index = start;
    for (int i = start + 1; i <= end; i++) {
      if (compare.cmp(pivot, norb[i]) == 1 ||
          compare.cmp(norb[i], pivot) == -1) {
        std::swap(norb[++pivot_index], norb[i]);
      } else if (compare.cmp(pivot, norb[i]) == 0 ||
                 compare.cmp(norb[i], pivot) == 0) {
        std::swap(norb[start], norb[i]);
        --i;
      }
    }
    std::swap(norb[pivot_index], norb[start]);

    return pivot_index;
  }
};
