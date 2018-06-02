// http://www.lintcode.com/zh-cn/problem/inorder-successor-in-bst
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  Solution() : pre_(0), succ_(0) {}
  /*
  * @param root: The root of the BST.
  * @param p: You need find the successor node of p.
  * @return: Successor of p.
  */
  TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
    if (!p) {
      return nullptr;
    }
    inorder(root, p);
    return succ_;
  }

  void inorder(TreeNode *root, TreeNode *p) {
    if (!root) {
      return;
    }

    inorder(root->left, p);
    if (pre_ == p) {
      succ_ = root;
    }
    pre_ = root;

    inorder(root->right, p);
  }
private:
  TreeNode *pre_;
  TreeNode *succ_;
};
