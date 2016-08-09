// http://www.lintcode.com/zh-cn/problem/digit-counts
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
   * param k : As description.
   * param n : As description.
   * return: How many k's between 0 and n.
   http://www.hawstein.com/posts/20.4.html
   当某一位的数字小于i时，那么该位出现i的次数为：更高位数字x当前位数
   当某一位的数字等于i时，那么该位出现i的次数为：更高位数字x当前位数+低位数字+1
   当某一位的数字大于i时，那么该位出现i的次数为：(更高位数字+1)x当前位数
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

int main()
{
  Solution so;
  auto ret = so.digitCounts(1, 1);
  cout << ret << endl;
  return 0;
}
