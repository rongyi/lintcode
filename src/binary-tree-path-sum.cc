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
  vector<vector<int>> binaryTreePathSumV1(TreeNode *root, int target) {
    vector<vector<int>> ret;
    if (root == nullptr)
      return ret;

    vector<int> aux;
    dfs(ret, aux, root, target);

    return ret;
  }
  vector<vector<int>> binaryTreePathSum(TreeNode *root, int target) {
    vector<vector<int>> ret;

    vector<int> cur;
    path_sum(root, target, cur, ret);

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

  // 这里 cur_sum_lst 是复制后调用，所以这里没有回朔的 pop_back 步骤
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

  void path_sum(TreeNode *root, int gap, vector<int> &cur, vector<vector<int>> &ret) {
    if (root == nullptr) {
      return;
    }
    cur.push_back(root->val);

    if (root->left == nullptr && root->right == nullptr) {
      if (gap == root->val) {
        ret.push_back(cur);
      }
    }
    path_sum(root->left, gap - root->val, cur, ret);
    path_sum(root->right, gap - root->val, cur, ret);
    cur.pop_back();
  }
};
