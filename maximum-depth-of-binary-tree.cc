// http://www.lintcode.com/zh-cn/problem/maximum-depth-of-binary-tree

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
   * @return: An integer
   */
  int maxDepth(TreeNode *root) {
    if (!root)
      return 0;
    int left_height = 1 + maxDepth(root->left);
    int right_height = 1 + maxDepth(root->right);
    return std::max(left_height, right_height);
  }
};
