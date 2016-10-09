// http://www.lintcode.com/zh-cn/problem/topological-sorting
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
   * @return: Any topological order for the given graph.
   */
  vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
    // write your code here
  }
};
