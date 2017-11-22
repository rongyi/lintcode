// http://www.lintcode.com/zh-cn/problem/sum-of-all-subsets
#include <vector>
#include <iostream>
#include <string>
#include <bitset>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /*
  * @param : the given number
  * @return: Sum of elements in subsets
  */
  int subSum(int n) {
    // For an input {x1, …, xn}, return 2n-1 (x1 + … + xn), since each term appears in that many sums.
    return (1 << (n - 1)) * sum(n);
  }
private:
  int sum(int n) {
    int ret = 0;
    for (int i = 0; i < n; ++i) {
      ret += (i + 1);
    }

    return ret;
  }
};
