// http://www.lintcode.com/zh-cn/problem/identical-binary-tree/
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
class Solution {
public:
  /**
   * @aaram a, b, the root of binary trees.
   * @return true if they are identical, or false.
   */
  bool isIdentical(TreeNode *a, TreeNode *b) {
    if (!a && b)
      return false;
    if (!b && a)
      return false;
    if (!a && !b)
      return true;
    return (a->val == b->val && isIdentical(a->left, b->left) &&
            isIdentical(a->right, b->right));
  }
};
