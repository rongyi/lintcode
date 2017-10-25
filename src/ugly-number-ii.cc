// http://www.lintcode.com/zh-cn/problem/ugly-number-ii
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
  /*
   * @param n an integer
   * @return the nth prime number as description.
   */
  int nthUglyNumber(int n) {
    // 三个乘数 2， 3， 5的index
    // 1x2, 2x2, 3x2, 4x2, 5x2, ...
    // 1x3, 2x3, 3x3, 4x3, 5x3, ...
    // 1x5, 2x5, 3x5, 4x5, 5x5, ...
    vector<long> ids(3, 0);
    vector<long> ugly_lst(n);

    ugly_lst[0] = 1;

    for (int i = 1; i < n; i++) {
      int a = ugly_lst[ids[0]] * 2;
      int b = ugly_lst[ids[1]] * 3;
      int c = ugly_lst[ids[2]] * 5;

      int min = std::min(a, std::min(b, c));

      if (a == min)
        ids[0]++;
      if (b == min)
        ids[1]++;
      if (c == min)
        ids[2]++;
      ugly_lst[i] = min;
    }

    return ugly_lst[n - 1];
  }
};
int main() {
  Solution so;
  auto ret = so.nthUglyNumber(9);
  cout << ret << endl;
  return 0;
}
