// http://www.lintcode.com/zh-cn/problem/flatten-binary-tree-to-linked-list/

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
   * @param root: a TreeNode, the root of the binary tree
   * @return: nothing
   */
  void flatten(TreeNode *root) {
    // write your code here
    if (!root)
      return;
    stack<TreeNode *> s;
    s.push(root);

    // in order tranverse
    // 1. clear left
    // 2. change right to the next element which sit on the
    // top of stack if exist
    while (!s.empty()) {
      auto p = s.top();
      s.pop();

      if (p->right)
        s.push(p->right);
      if (p->left)
        s.push(p->left);
      p->left = nullptr;
      if (!s.empty())
        p->right = s.top();
    }
  }
};
