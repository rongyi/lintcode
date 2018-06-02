// http://www.lintcode.com/zh-cn/problem/tower-of-hanoi
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Solution {
public:
  /**
   * @param n: the number of disks
   * @return: the order of moves
   */
  vector<string> towerOfHanoi(int n) {
    vector<string> ret;

    doHanoi(n, 'A', 'C', 'B', ret);

    return ret;
  }

private:
  string cacat(char from, char to) {
    std::stringstream ss;
    ss << "from " << from << " to " << to;
    return ss.str();
  }
  void doHanoi(int n, char from, char to, char aux, vector<string> &ret) {
    if (n == 1) {
      ret.push_back(cacat(from, to));
      return;
    }
    // 实现这个算法可以简单分为三个步骤：
    // （1）把n-1个盘子由A 移到 B；
    // （2）把第n个盘子由 A移到 C；
    // （3）把n-1个盘子由B 移到 C；
    doHanoi(n - 1, from, aux, to, ret);
    ret.push_back(cacat(from, to));
    doHanoi(n - 1, aux, to, from, ret);
  }
};
