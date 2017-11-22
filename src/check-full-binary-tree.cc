// http://www.lintcode.com/zh-cn/problem/check-full-binary-tree
class Solution {
public:
  /*
  * @param : the given tree
  * @return: Whether it is a full tree
  */
  bool isFullTree(TreeNode *root) {
    if (!root) {
      return true;
    }
    if (root->left == nullptr && root->right == nullptr) {
      return true;
    }
    if (root->left != nullptr && root->right != nullptr) {
      return isFullTree(root->left) && isFullTree(root->right);
    }
    return false;
  }
};
