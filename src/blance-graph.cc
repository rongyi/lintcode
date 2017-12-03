// http://www.lintcode.com/zh-cn/problem/balance-graph

#include <bitset>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /*
  * @param edges: a directed graph where each edge is represented by a tuple
  * @return: the number of edges
  */
  int balanceGraphTODO(vector<vector<int>> &edges) {
    std::unordered_map<int, int> in;
    std::unordered_map<int, int> out;
    std::unordered_set<int> nodes;
    for (auto &v : edges) {
      out[v[0]] += v[2];
      in[v[1]] += v[2];
      nodes.insert(v[0]);
      nodes.insert(v[1]);
    }
    std::unordered_map<int, int> net;
    for (auto &n : nodes) {
      int delta = out[n] - in[n];
      if (delta != 0) {
        net[n] = delta;
      }
    }
    if (net.size() == 0) {
      return 0;
    }
    // 这是暴力结果
    return net.size() - 1;
  }
};
int main() {
  Solution so;
  vector<vector<int>> test{{7,9,1},{9,8,59},{4,0,46},{7,6,92},{7,6,92},{2,3,93},{1,3,96},{6,8,70},{2,4,36},{3,1,23},{8,9,42},{8,7,45},{2,4,24},{9,8,17},{5,7,89},{0,2,65},{1,0,91},{5,6,2},{8,9,24},{4,1,41}};
  // [-166, -116, -72, -35, 9, 27, 51, 88, 91, 123]
  // 要算好 88 51 27 ==> 166
  // 123 - 116 余 7
  // 91 - 72 余 19
  // 7 + 9 + 19 ==> 35 , 所以这里需要链接8根
  // 这里dp算这样的组合

  auto ret = so.balanceGraphTODO(test);
  cout << ret << endl;
  return 0;
}
