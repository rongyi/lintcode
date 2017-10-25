// http://www.lintcode.com/zh-cn/problem/lowest-common-ancestor
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
    this->left = this->right = NULL;
  }
};

class Solution {
public:
  /**
   * @param root: The root of the binary search tree.
   * @param a and b: two nodes in a Binary.
   * @return: Return the least common ancestor(LCA) of the two nodes.
   */
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *a, TreeNode *b) {
    if (!root || root == a || root == b)
      return root;
    TreeNode *left = lowestCommonAncestor(root->left, a, b);
    TreeNode *right = lowestCommonAncestor(root->right, a, b);

    if (left && right)
      return root;

    return (left != nullptr) ? left : right;
  }
};
