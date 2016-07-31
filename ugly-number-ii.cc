// http://www.lintcode.com/zh-cn/problem/ugly-number-ii
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

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
int main()
{
  Solution so;
  auto ret = so.nthUglyNumber(9);
  cout << ret << endl;
  return 0;
}