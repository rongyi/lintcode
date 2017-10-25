// http://www.lintcode.com/zh-cn/problem/minimum-depth-of-binary-tree
#include <climits>
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

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
   * @param root: The root of binary tree.
   * @return: An integer
   */
  int do_min(TreeNode *root) {
    if (!root)
      return 0;
    if (root->left == nullptr && root->right == nullptr)
      return 1;
    int left_height = INT_MAX;
    int right_height = INT_MAX;
    if (root->left)
      left_height = do_min(root->left);
    if (root->right)
      right_height = do_min(root->right);

    return std::min(left_height, right_height) + 1;
  }

  int minDepth(TreeNode *root) {
    if (!root)
      return 0;
    return do_min(root);
  }
};
