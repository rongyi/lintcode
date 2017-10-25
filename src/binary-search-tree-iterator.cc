// http://www.lintcode.com/zh-cn/problem/binary-search-tree-iterator
#include <iostream>
#include <stack>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::stack;

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
 * Example of iterate a tree:
 * BSTIterator iterator = BSTIterator(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
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

class BSTIterator {
public:
  //@param root: The root of binary tree.
  BSTIterator(TreeNode *root) {
    while (root) {
      s_.push(root);
      root = root->left;
    }
  }

  //@return: True if there has next node, or false
  bool hasNext() { return !s_.empty(); }

  //@return: return next node
  TreeNode *next() {
    TreeNode *cur = s_.top();
    s_.pop();
    TreeNode *ret = cur;

    if (cur->right) {
      cur = cur->right;
      while (cur) {
        s_.push(cur);
        cur = cur->left;
      }
    }

    return ret;
  }

private:
  stack<TreeNode *> s_;
};
