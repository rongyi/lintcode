// http://www.lintcode.com/zh-cn/problem/next-sparse-number
#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /*
  * @param : a number
  * @return: return the next sparse number behind x
  */
  int nextSparseNum(int x) {
    while (!isSparseNum(x)) {
      x = chanit(x);
    }
    return x;
  }

  int chanit(int x) {
    for (int i = 0; i < 31; i++) {
      auto cur = (x & (1 << i)) >> i;
      auto nei = (x & (1 << (i + 1))) >> (i + 1);
      // we found con
      if (cur == 1 && nei == 1) {
        x &= ~(1 << i);
        x &= ~(1 << (i + 1));
        x |= (1 << (i + 2) % 32);
        return x;
      }
    }
    return x;
  }
  bool isSparseNum(int x) {
    while (x) {
      auto b = x & 0b1;
      auto n = x & 0b10;
      if (b == 0b1 && n == 0b10) {
        return false;
      }
      x >>= 1;
    }
    return true;
  }
};
int main() {
  Solution so;
  auto ret = so.nextSparseNum(44);
  cout << ret << endl;
  return 0;
}
