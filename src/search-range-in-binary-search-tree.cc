// http://www.lintcode.com/zh-cn/problem/search-range-in-binary-search-tree
#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

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
    this->left = this->right = NULL;
  }
};

class Solution {
public:
  /**
   * @param root: The root of the binary search tree.
   * @param k1 and k2: range k1 to k2.
   * @return: Return all keys that k1<=key<=k2 in ascending order.
   */
  vector<int> searchRange(TreeNode* root, int k1, int k2) {
    vector<int> all_nodes = inorderTraversal(root);
    vector<int> ret;
    for (auto i : all_nodes) {
      if (i >= k1 && i <= k2) {
        ret.push_back(i);
      }
    }

    return ret;
  }
private:
  vector<int> inorderTraversal(TreeNode *root) {
    std::vector<int> ret;
    inner(root, ret);
    return ret;
  }
  void inner(TreeNode *root, std::vector<int> &ret) {
    if (root) {
      inner(root->left, ret);
      ret.push_back(root->val);
      inner(root->right, ret);
    }
  }
};
