// http://www.lintcode.com/zh-cn/problem/clone-binary-tree
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

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
   * @param root: The root of binary tree
   * @return root of new tree
   */
  TreeNode *cloneTree(TreeNode *root) {
    if (!root)
      return nullptr;
    TreeNode *new_node = new TreeNode(root->val);
    doClone(root->left, new_node, true);
    doClone(root->right, new_node, false);

    return new_node;
  }

  void doClone(TreeNode *root, TreeNode *prarent, bool isLeft) {
    if (!root)
      return;

    TreeNode *new_node = new TreeNode(root->val);

    if (isLeft) {
      prarent->left = new_node;
    } else {
      prarent->right = new_node;
    }

    doClone(root->left, new_node, true);
    doClone(root->right, new_node, false);
  }
};
