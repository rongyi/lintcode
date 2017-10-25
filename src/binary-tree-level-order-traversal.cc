// http://www.lintcode.com/zh-cn/problem/binary-tree-level-order-traversal

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
  /**
   * @param root: The root of binary tree.
   * @return: Level order a list of lists of integer
   */
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> ret;
    traverse(root, 1, ret);
    return ret;
  }

private:
  void traverse(TreeNode *root, unsigned level, vector<vector<int>> &ret) {
    if (!root)
      return;
    if (level > ret.size()) {
      ret.push_back(vector<int>());
    }
    ret[level - 1].push_back(root->val);
    traverse(root->left, level + 1, ret);
    traverse(root->right, level + 1, ret);
  }
};
