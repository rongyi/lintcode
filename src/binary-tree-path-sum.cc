// http://www.lintcode.com/zh-cn/problem/binary-tree-path-sum

#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class TreeNode {
public:
  int val;
  TreeNode *left, *right;
  TreeNode(int val) {
    this->val = val;
    this->left = this->right = nullptr;
  }
};

class Solution {
public:
  /**
   * @param root the root of binary tree
   * @param target an integer
   * @return all valid paths
   */
  vector<vector<int>> binaryTreePathSum(TreeNode *root, int target) {
    vector<vector<int>> ret;
    if (root == nullptr)
      return ret;

    vector<int> aux;
    dfs(ret, aux, root, target);

    return ret;
  }

private:
  int getSum(vector<int> path) {
    int sum = 0;
    for (unsigned i = 0; i < path.size(); i++) {
      sum += path[i];
    }
    return sum;
  }

  void dfs(vector<vector<int>> &ret, vector<int> cur_sum_lst,
           const TreeNode *cur_node, const int target) {
    cur_sum_lst.push_back(cur_node->val);
    if (cur_node->left == nullptr && cur_node->right == nullptr) {
      if (getSum(cur_sum_lst) == target) {
        ret.push_back(cur_sum_lst);
      }
      return;
    }
    if (cur_node->left) {
      dfs(ret, cur_sum_lst, cur_node->left, target);
    }

    if (cur_node->right) {
      dfs(ret, cur_sum_lst, cur_node->right, target);
    }
  }
};
