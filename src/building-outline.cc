// http://www.lintcode.com/zh-cn/problem/building-outline
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::multiset;
using std::pair;

class Solution {
public:
  /**
   * @param buildings: A list of lists of integers
   * @return: Find the outline of those buildings
   */
  vector<vector<int>> buildingOutline(vector<vector<int>> &buildings) {
    vector<vector<int>> ret;
    for (auto x : buildings) {
      points_.insert(x[0]);
      points_.insert(x[1]);
      start_[x[0]].push_back(x[2]);
      end_[x[1]].push_back(x[2]);
    }

    int pre = 0;
    heap_.insert(0);
    for (auto cur : points_) {
      auto prev = *heap_.rbegin();
      if (prev) {
        if (ret.empty() || prev != ret[ret.size() - 1][2])
          ret.push_back(vector<int>{pre, cur, prev});
        else
          ret[ret.size() - 1][1] = cur;
      }
      for (auto x : start_[cur])
        heap_.insert(x);
      for (auto x : end_[cur])
        heap_.erase(heap_.find(x));
      pre = cur;
    }

    return ret;
  }

private:
  std::set<int> points_;

  std::map<int, vector<int>> start_;
  std::map<int, vector<int>> end_;

  multiset<int> heap_;
};
