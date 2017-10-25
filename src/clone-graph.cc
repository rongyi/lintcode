// http://www.lintcode.com/zh-cn/problem/clone-graph
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;

struct UndirectedGraphNode {
  int label;
  vector<UndirectedGraphNode *> neighbors;
  UndirectedGraphNode(int x) : label(x){};
};

class Solution {
public:
  /**
   * @param node: A undirected graph node
   * @return: A undirected graph node
   */
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    unordered_map<int, UndirectedGraphNode *> aux_map;

    return doClone(node, aux_map);
  }

  UndirectedGraphNode *
  doClone(UndirectedGraphNode *node,
          unordered_map<int, UndirectedGraphNode *> &save_map) {
    if (!node)
      return nullptr;

    if (save_map.find(node->label) != save_map.end()) {
      return save_map[node->label];
    }

    UndirectedGraphNode *new_node = new UndirectedGraphNode(node->label);
    save_map[node->label] = new_node;

    for (auto ugp : node->neighbors) {
      UndirectedGraphNode *new_nei = doClone(ugp, save_map);
      new_node->neighbors.push_back(new_nei);
    }

    return new_node;
  }
};
