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
  Solution() : sum_(0) {}
  /**
   * @param root the root of binary tree
   * @return the new root
   */
  TreeNode *convertBST(TreeNode *root) {
    if (!root)
      return nullptr;
    convertBST(root->right);
    root->val += sum_;
    sum_ = root->val;
    convertBST(root->left);

    return root;
  }

private:
  int sum_;
};
