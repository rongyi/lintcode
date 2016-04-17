// http://www.lintcode.com/zh-cn/problem/binary-tree-level-order-traversal-ii

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
   * @param root : The root of binary tree.
   * @return : buttom-up level order a list of lists of integer
   */
public:
  vector<vector<int> > levelOrderBottom(TreeNode *root) {
    vector< vector<int> > ret;
    if (!root)
      return ret;
    queue<TreeNode*> queue;
    queue.push(root);
    while (!queue.empty()) {
      vector<int> tmp;
      int cur_cnt = queue.size();
      for (int i = 0; i < cur_cnt; i++) {
        tmp.push_back(queue.front()->val);
        if (queue.front()->left) {
          queue.push(queue.front()->left);
        }
        if (queue.front()->right) {
          queue.push(queue.front()->right);
        }
        queue.pop();
      }
      ret.insert(ret.begin(), tmp);
    }

    return ret;
  }

};
