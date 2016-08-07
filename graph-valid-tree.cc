// http://www.lintcode.com/zh-cn/problem/graph-valid-tree
#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param n an integer
   * @param edges a list of undirected edges
   * @return true if it's a valid tree, or false
   */
  bool validTree(int n, vector<vector<int>>& edges) {
    if (n < 0)
      return false;
    if (n <= 1 && edges.empty())
      return true;
    vector<vector<int>> g(n, vector<int>());
    vector<bool> visited(n, false);
    for (auto &e : edges) {
      g[e[0]].push_back(e[1]);
      g[e[1]].push_back(e[0]);
    }
    if (!dfs(g, visited, 0, -1))
      return false;
    for (auto i : visited) {
      // has island node
      if (!i) {
        return false;
      }
    }

    return true;
  }
private:
  bool dfs(const vector<vector<int>> &g, vector<bool> &visited, int cur, int pre) {
    if (visited[cur])
      return false;
    visited[cur] = true;
    for (auto i : g[cur]) {
      if (i != pre) {
        if (!dfs(g, visited, i, cur))
          return false;
      }
    }
    return true;
  }
};
