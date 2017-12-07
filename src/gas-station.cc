// http://www.lintcode.com/zh-cn/problem/gas-station

#include <vector>
using std::vector;

class Solution {
public:
  /**
   * @param gas: a vector of integers
   * @param cost: a vector of integers
   * @return: an integer
   */
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int total = 0;
    int j = -1;
    for (int i = 0, sum = 0; i < gas.size(); i++) {
      sum += gas[i] - cost[i];
      // 不管从哪里开始兜一圈的油耗总和不变，
      total += gas[i] - cost[i];
      // 表示从前面某个点开始到当前节点“够不着”
      if (sum < 0) {
        j = i; // the next possible index;
        sum = 0;
      }
    }
    return total >= 0 ? j + 1: -1;
  }
};
