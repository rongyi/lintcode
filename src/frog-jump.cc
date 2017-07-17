// http://www.lintcode.com/zh-cn/problem/frog-jump
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param stones a list of stones' positions in sorted ascending order
   * @return true if the frog is able to cross the river or false
   */
  bool canCross(vector<int>& stones) {
    std::unordered_map<int, bool> aux;
    return do_cross(stones, 0, 0, aux);
  }

  bool do_cross(vector<int> &stones, int pos, int step, std::unordered_map<int, bool> &aux) {
    const int n = stones.size();
    int key = pos | (step << 11);
    if (pos >= n - 1)
      return true;
    if (aux.find(key) != aux.end())
      return aux[key];

    for (int i = pos + 1; i < n; ++i) {
      int dist = stones[i] - stones[pos];
      if (dist < step - 1)
        continue;
      if (dist > step + 1)
        return aux[key] = false;
      if (do_cross(stones, i, dist, aux))
        return aux[key] = true;
    }

    return aux[key] = false;
  }
};
