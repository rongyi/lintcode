// http://www.lintcode.com/zh-cn/problem/digit-counts
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
   * param k : As description.
   * param n : As description.
   * return: How many k's between 0 and n.
   http://www.hawstein.com/posts/20.4.html
  */
  int digitCounts(int k, int n) {
    int ret = 0;
    if (k == 0) {
      ret = 1;
    }
    for (int i = 1; i <= n; i++) {
      int cur = i;
      while (cur) {
        if (cur % 10 == k)
          ret++;
        cur /= 10;
      }
    }
    return ret;
  }
};

int main() {
  Solution so;
  auto ret = so.digitCounts(1, 1);
  cout << ret << endl;
  return 0;
}
