// http://www.lintcode.com/zh-cn/problem/route-between-two-nodes-in-graph
#include <vector>
#include <iostream>
#include <string>

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
  DirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
  /**
   * @param graph: A list of Directed graph node
   * @param s: the starting Directed graph node
   * @param t: the terminal Directed graph node
   * @return: a boolean value
   */
  bool hasRoute(vector<DirectedGraphNode*> graph,
                DirectedGraphNode* s, DirectedGraphNode* t) {
    // write your code here
  }
};
