// http://www.lintcode.com/zh-cn/problem/binary-tree-inorder-traversal
#include <vector>
#include <iostream>
#include <string>
#include <stack>

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
#include <vector>
using namespace std;

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
   * @param root: The root of binary tree.
   * @return: Inorder in vector which contains node values.
   */
public:
  vector<int> inorderTraversalRecursive(TreeNode *root) {
    std::vector<int> ret;
    inner(root, ret);
    return ret;
  }
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> ret;
    std::stack<const TreeNode*> s;
    const TreeNode *p = root;
    while (!s.empty() || p != nullptr) {
      if (p != nullptr) {
        s.push(p);
        p = p->left;
      } else {
        p = s.top();
        s.pop();
        ret.push_back(p->val);
        p = p->right;
      }
    }

    return ret;
  }

private:
  void inner(TreeNode *root, std::vector<int> &ret) {
    if (root) {
      inner(root->left, ret);
      ret.push_back(root->val);
      inner(root->right, ret);
    }
  }
};
