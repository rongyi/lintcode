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
    // empty node or one node with empty edge is a valid tree
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
  /*
    我们知道如果是树的话， 所有的节点必须是连接的， 也就是说必须是连通图， 而且不能有环， 所以我们的焦点就变成了验证是否是
    连通图和是否含有环。 我们首先用DFS来做， 根据pair来建立一个图的结构， 用邻接链表来表示， 还需要一个一位数组v来记录某
    个节点是否被访问过， 然后我们用DFS来搜索节点0， 遍历的思想是， 当DFS到某个节点， 先看当前节点是否被访问过， 如果已经
    被访问过， 说明环存在， 直接返回false， 如果未被访问过， 我们现在将其状态标记为已访问过， 然后我们到邻接链表里去找跟
    其相邻的节点继续递归遍历， 注意我们还需要一个变量pre来记录上一个节点， 以免回到上一个节点， 这样遍历结束后， 我们就把
    和节点0相邻的节点都标记为true， 然后我们在看v里面是否还有没被放过的节点， 如果有， 则说明图不是完全连通的，
    返回false， 反之返回true
  */
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
