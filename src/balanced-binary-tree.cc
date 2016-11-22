// http://www.lintcode.com/zh-cn/problem/balanced-binary-tree

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
#include <cstdio>
using namespace std;

class Solution {
public:
  /**
   * @param root: The root of binary tree.
   * @return: True if this Binary tree is Balanced, or false.
   */
  bool isBalanced(TreeNode *root) {
    if (!root)
      return true;
    int delta = abs(height(root->left) - height(root->right));
    if (delta > 1)
      return false;
    return isBalanced(root->left) && isBalanced(root->right);
  }

private:
  int height(TreeNode *root) {
    if (!root)
      return 0;
    return 1 + max(height(root->left), height(root->right));
  }
};
