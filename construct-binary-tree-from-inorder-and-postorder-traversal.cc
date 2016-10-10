// http://www.lintcode.com/zh-cn/problem/construct-binary-tree-from-inorder-and-postorder-traversal
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
    this->left = this->right = nullptr;
  }
};

class Solution {
  /**
   *@param inorder : A list of integers that inorder traversal of a tree
   *@param postorder : A list of integers that postorder traversal of a tree
   *@return : Root of a tree
   */
public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    if (inorder.empty() || inorder.size() != postorder.size())
      return nullptr;
    TreeNode *ret = nullptr;

    doBuild(ret, postorder, inorder, postorder.size() - 1, 0, postorder.size());

    return ret;
  }
private:
  void doBuild(TreeNode * &root, vector<int> &postorder, vector<int> &inorder,
               int post_index, int in_index, int in_size) {
    if (in_index >= in_size)
      return;
    root = new TreeNode(postorder[post_index]);
    int cur_in_size;
    for (int i = in_index; i < in_size; i++) {
      if (inorder[i] == postorder[post_index]) {
        cur_in_size = i;
        break;
      }
    }

    doBuild(root->left, postorder, inorder, post_index - (in_size - cur_in_size), in_index, cur_in_size);
    doBuild(root->right, postorder, inorder, post_index - 1, cur_in_size + 1, in_size);
  }
};
