// http://www.lintcode.com/zh-cn/problem/route-between-two-nodes-in-graph
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
struct DirectedGraphNode {
  int label;
  vector<DirectedGraphNode *> neighbors;
  DirectedGraphNode(int x) : label(x){};
};

class Solution {
public:
  /**
   * @param graph: A list of Directed graph node
   * @param s: the starting Directed graph node
   * @param t: the terminal Directed graph node
   * @return: a boolean value
   */
  bool hasRoute(vector<DirectedGraphNode *> graph, DirectedGraphNode *s,
                DirectedGraphNode *t) {
    bool routeFounded = false;

    for (auto cur_node : graph) {
      if (cur_node == s) {
        dfs(cur_node, t, routeFounded);
      }
    }

    return routeFounded;
  }

  void dfs(DirectedGraphNode *cur_node, const DirectedGraphNode *target,
           bool &routeFounded) {
    if (cur_node == target) {
      routeFounded = true;
      return;
    }
    for (auto cur_neighbor : cur_node->neighbors) {
      if (cur_neighbor == target) {
        routeFounded = true;
        return;
      } else {
        dfs(cur_neighbor, target, routeFounded);
      }
    }
  }
};
