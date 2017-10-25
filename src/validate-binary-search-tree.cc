// http://www.lintcode.com/zh-cn/problem/validate-binary-search-tree

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
   * @param root: The root of binary tree.
   * @return: True if the binary tree is BST, or false
   */
  bool isValidBST(TreeNode *root) {
    if (root == NULL)
      return true;

    return helper(root, INT_MIN, INT_MAX);
  }

  bool helper(TreeNode *root, int lower, int upper) {
    if (root == NULL)
      return true;

    if (root->val <= lower || root->val >= upper) {
      bool right_max = root->val == INT_MAX && root->right == NULL;
      bool left_min = root->val == INT_MIN && root->left == NULL;
      if (!(right_max || left_min)) {
        return false;
      }
    }
    bool isLeftValidBST = helper(root->left, lower, root->val);
    bool isRightValidBST = helper(root->right, root->val, upper);

    return isLeftValidBST && isRightValidBST;
  }
};
