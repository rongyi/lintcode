// http://www.lintcode.com/zh-cn/problem/construct-binary-tree-from-preorder-and-inorder-traversal
#include <iostream>
#include <string>
#include <vector>

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
    this->left = this->right = nullptr;
  }
};

class Solution {
  /**
   *@param preorder : A list of integers that preorder traversal of a tree
   *@param inorder : A list of integers that inorder traversal of a tree
   *@return : Root of a tree
   */
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.empty() || preorder.size() != inorder.size())
      return nullptr;

    TreeNode *ret = nullptr;

    doBuild(ret, preorder, inorder, 0, 0, inorder.size());

    return ret;
  }

private:
  void doBuild(TreeNode *&root, vector<int> &preorder, vector<int> &inorder,
               int pre_index, int in_index, int in_size) {
    if (in_index >= in_size)
      return;
    root = new TreeNode(preorder[pre_index]);
    int cur_in_size;
    // find the index of root node in inorder
    for (int i = in_index; i < in_size; i++) {
      if (inorder[i] == preorder[pre_index]) {
        cur_in_size = i;
        break;
      }
    }
    // left root's index is pre_index + 1, and in_index is not change, and have cur_in_size elements
    doBuild(root->left, preorder, inorder, pre_index + 1, in_index,
            cur_in_size);
    // right root's index, first in_order index and size
    doBuild(root->right, preorder, inorder,
            pre_index + cur_in_size - in_index + 1, cur_in_size + 1, in_size);
  }
};
