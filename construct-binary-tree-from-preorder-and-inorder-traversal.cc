// http://www.lintcode.com/zh-cn/problem/construct-binary-tree-from-preorder-and-inorder-traversal
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
  /**
   *@param preorder : A list of integers that preorder traversal of a tree
   *@param inorder : A list of integers that inorder traversal of a tree
   *@return : Root of a tree
   */
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    // write your code here
  }
};
