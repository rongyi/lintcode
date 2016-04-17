// http://www.lintcode.com/zh-cn/problem/binary-tree-preorder-traversal

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

class Solution {
public:
  /**
   * @param root: The root of binary tree.
   * @return: Preorder in vector which contains node values.
   */
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> ret;
    const TreeNode *p;
    stack<const TreeNode *> s;
    p = root;
    if (p)
      s.push(p);

    while (!s.empty()) {
      p = s.top();
      s.pop();
      ret.push_back(p->val);

      if (p->right)
        s.push(p->right);
      if (p->left)
        s.push(p->left);
    }
    return ret;

  }
private:
  void inner(TreeNode *root, std::vector<int> &ret) {
    if (root) {
      ret.push_back(root->val);
      inner(root->left, ret);
      inner(root->right, ret);
    }
  }
};
