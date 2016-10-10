// http://www.lintcode.com/zh-cn/problem/binary-tree-inorder-traversal

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
#include <vector>
using namespace std;


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
  /**
   * @param root: The root of binary tree.
   * @return: Inorder in vector which contains node values.
   */
public:
  vector<int> inorderTraversal(TreeNode *root) {
    std::vector<int> ret;
    inner(root, ret);
    return ret;
  }
private:
  void inner(TreeNode *root, std::vector<int> &ret) {
    if (root) {
      inner(root->left, ret);
      ret.push_back(root->val);
      inner(root->right, ret);
    }
  }
};
