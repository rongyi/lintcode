// http://www.lintcode.com/zh-cn/problem/count-of-smaller-number
#include <algorithm>
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
   * @param A: An integer array
   * @return: The number of element in the array that
   *          are smaller that the given integer
   */
  vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
    std::sort(A.begin(), A.end());
    vector<int> ret;
    for (auto q : queries) {
      auto count = std::lower_bound(A.begin(), A.end(), q) - A.begin();
      ret.push_back(count);
    }

    return ret;
  }
};
