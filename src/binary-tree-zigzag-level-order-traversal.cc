// http://www.lintcode.com/zh-cn/problem/binary-tree-zigzag-level-order-traversal

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
   * @return: A list of lists of integer include
   *          the zigzag level order traversal of its nodes' values
   */
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> ret;
    traverse(root, 1, ret, true);
    return ret;
  }

private:
  void traverse(TreeNode *root, unsigned level, vector<vector<int>> &ret,
                bool left_to_right) {
    if (!root)
      return;
    if (level > ret.size()) {
      ret.push_back(vector<int>());
    }
    if (left_to_right) {
      ret[level - 1].push_back(root->val);
    } else {
      ret[level - 1].insert(ret[level - 1].begin(), root->val);
    }
    traverse(root->left, level + 1, ret, !left_to_right);
    traverse(root->right, level + 1, ret, !left_to_right);
  }
};
