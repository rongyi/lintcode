// http://www.lintcode.com/zh-cn/problem/convert-bst-to-greater-tree
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
   * @return the new root
   */
  TreeNode* convertBST(TreeNode* root) {

  }
};
