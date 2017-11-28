// http://www.lintcode.com/zh-cn/problem/validate-binary-search-tree
#include <climits>

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
    if (root == nullptr)
      return true;

    return helper(root, INT_MIN, INT_MAX);
  }

  bool helper(TreeNode *root, int lower, int upper) {
    if (root == nullptr)
      return true;

    // the left most node is INT_MIN, or the right most node is INT_MAX
    if (root->val <= lower || root->val >= upper) {
      bool right_max = root->val == INT_MAX && root->right == nullptr;
      bool left_min = root->val == INT_MIN && root->left == nullptr;
      if (!(right_max || left_min)) {
        return false;
      }
    }
    bool isLeftValidBST = helper(root->left, lower, root->val);
    bool isRightValidBST = helper(root->right, root->val, upper);

    return isLeftValidBST && isRightValidBST;

    // simple version, but with no check of INT_MAX or INT_MIN
    // return root->val > lower && root->val < upper
    //            && isValidBST(root->left, lower, root->val)
    //            && isValidBST(root->right, root->val, upper);
  }
};
