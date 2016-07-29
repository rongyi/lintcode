// http://www.lintcode.com/zh-cn/problem/unique-binary-search-trees
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
   * @paramn n: An integer
   * @return: An integer
   */
  int numTrees(int n) {
    // f(n) = f(n-1)f(0) + f(n-2)f(1) + f(n-3)f(2) + ... + f(1)f(n-2) + f(n-1)f(0)
    vector<int> ret_vec(n + 1, 0);
    ret_vec[0] = 1;
    ret_vec[1] = 1;
    ret_vec[2] = 2;
    for (int i = 3; i <= n; i++) {
      for (int j = i - 1; j >= 0; j--) {
        ret_vec[i] += ret_vec[j] * ret_vec[i - 1 - j];
      }
    }

    return ret_vec[n];
  }
};
