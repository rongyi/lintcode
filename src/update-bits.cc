// http://www.lintcode.com/zh-cn/problem/update-bits
#include <bitset>
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
   *@param n, m: Two integer
   *@param i, j: Two bit positions
   *return: An integer
   */
  int updateBits(int n, int m, int i, int j) {
    if (i > j)
      return -1;

    for (int ni = i, k = 0; ni <= j; ni++, k++) {
      // first clear the bit
      n &= ~(1 << ni);
      // then add m
      int x = (m & (1 << k)) >> k;
      n |= (x << ni);
    }

    return n;
  }
};

int main() {
  auto a = 1024;
  auto b = 21;
  Solution so;
  auto ret = so.updateBits(a, b, 2, 6);
  cout << ret << endl;

  return 0;
}
