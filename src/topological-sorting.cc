// http://www.lintcode.com/zh-cn/problem/topological-sorting
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;

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
  Solution() : in_degree_cout_() { in_degree_cout_.clear(); }
  /**
   * @param graph: A list of Directed graph node
   * @return: Any topological order for the given graph.
   */
  vector<DirectedGraphNode *> topSort(vector<DirectedGraphNode *> graph) {
    vector<DirectedGraphNode *> ret;

    calculateInDegree(graph);

    for (auto dgn : graph) {
      // find the first node which in degree is 0 and dive in
      if (in_degree_cout_[dgn] == 0) {
        dfs(dgn, ret);
      }
    }

    return ret;
  }

private:
  void calculateInDegree(const vector<DirectedGraphNode *> &graph) {
    for (auto dgn : graph) {
      for (auto cur_neighbor : dgn->neighbors) {
        if (in_degree_cout_.find(cur_neighbor) == in_degree_cout_.end()) {
          in_degree_cout_[cur_neighbor] = 1;
        } else {
          ++in_degree_cout_[cur_neighbor];
        }
      }
    }
  }

  void dfs(DirectedGraphNode *node, vector<DirectedGraphNode *> &ret) {
    ret.push_back(node);
    // eliminate reentrance
    in_degree_cout_[node]--;

    for (auto cur_neighbor : node->neighbors) {
      --in_degree_cout_[cur_neighbor];

      if (in_degree_cout_[cur_neighbor] == 0) {
        dfs(cur_neighbor, ret);
      }
    }
  }

private:
  unordered_map<DirectedGraphNode *, int> in_degree_cout_;
};
