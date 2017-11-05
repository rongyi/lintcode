// http://www.lintcode.com/zh-cn/problem/lights-switcher
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
  * @param : number of lights
  * @param : number of operations
  * @return: the number of status
  * 1: on 0: off
  * Initial status
  * 1 1 1 1 1 1
  * ----------------
  * flip by one time of each method
  * 0 0 0 0 0 0 ...
  * 1 0 1 0 1 0 ...
  * 0 1 0 1 0 1 ...
  * 0 1 1 0 1 1 ...

  1. 当m和n其中有任意一个数是0时，返回1
  2. 当n = 1时: 只有两种情况，0和1
  3. 当n = 2时:
     这时候要看m的次数，如果m = 1，那么有三种状态 00, 10, 01
     当m > 1时，那么有四种状态，00，01，10，11 ==>可以构造出2位的所有可能
  4. 当m = 1时: 此时n至少为3，那么我们有四种状态，000, 101, 010, 011
  5. 当m = 2时: 此时n至少为3,我们有七种状态：111,101,010,100,000,001,110
  6. 当m > 2时: 此时n至少为3,我们有八种状态：111,101,010,100,000,001,110,011,可以构造出全部8种
  */
  int flipLights(int n, int m) {
    if (n == 0 || m == 0) {
      return 1;
    }
    if (n == 1) {
      return 2;
    }
    if (n == 2) {
      return m == 1 ? 3 : 4;
    }
    // now we have n >= 3
    if (m == 1) {
      return 4;
    }
    return m == 2 ? 7 : 8;
  }
};
