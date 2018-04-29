// http://www.lintcode.com/zh-cn/problem/find-leaves-of-binary-tree
#include <vector>
#include <iostream>
#include <string>
#include <bitset>

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
    this->left = this->right = NULL;
  }
};

class Solution {
public:
  /*
  * @param root: the root of binary tree
  * @return: collect and remove all leaves
  */
  vector<vector<int>> findLeaves(TreeNode * root) {
    vector<vector<int>> ret;
    help(root, ret);

    return ret;
  }

  int help(TreeNode *root, vector<vector<int>> &ret) {
    if (!root) {
      return -1;
    }
    int depth = 1 + std::max(help(root->left, ret), help(root->right, ret));
    if (depth >= ret.size()) {
      ret.resize(depth + 1);
    }
    ret[depth].push_back(root->val);

    return depth;
  }
};
