// http://www.lintcode.com/zh-cn/problem/house-robber
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
   * @param A: An array of non-negative integers.
   * return: The maximum amount of money you can rob tonight
   dp: f[n]=max(f[n-1], f[n-2] + money[n])
   */
  long long houseRobber(vector<int> a) {
    if (a.empty())
      return 0;
    const int n = a.size();
    vector<long long> ret(n, 0);

    ret[0] = a[0];
    ret[1] = std::max(a[0], a[1]);
    for (int i = 2; i < n; i++) {
      ret[i] = std::max(ret[i - 1], ret[i - 2] + a[i]);
    }

    return ret[n - 1];
  }
};
