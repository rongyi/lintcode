// http://www.lintcode.com/zh-cn/problem/remove-node-in-binary-search-tree
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

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
   * @param value: Remove the node with given value.
   * @return: The root of the binary search tree after removal.
   */
  TreeNode *removeNode(TreeNode *root, int value) {
    if (root == nullptr)
      return root;
    // point to the deleted node
    TreeNode *p;
    // point to parent node of delete target node
    TreeNode *q;
    p = root;
    q = root;

    while (p) {
      if (value == p->val) {
        break;
      } else if (value < p->val) {
        q = p;
        p = p->left;
      } else {
        q = p;
        p = p->right;
      }
    }

    // we doesnt find the target
    if (p == nullptr)
      return root;

    if (p->left == nullptr && p->right == nullptr) {
      if (p == q) {
        return nullptr;
      } else {
        if (q->left == p) {
          q->left = nullptr;
        } else {
          q->right = nullptr;
        }
      }
    }
    if (p->left == nullptr || p->right == nullptr) {
      if (p->left == nullptr) {
        if (p == q) {
          return q->right;
        } else {
          if (q->left == p) {
            q->left = p->right;
          } else {
            q->right = p->right;
          }
        }
      } else {
        if (p == q) {
          return q->left;
        } else {
          if (q->left == p) {
            q->left = p->left;
          } else {
            q->right = p->left;
          }
        }
      }
    }

    if (p->left != nullptr && p->right != nullptr) {
      TreeNode *pioneer = p->right;
      TreeNode *cover = p;
      while (pioneer->left != nullptr) {
        cover = pioneer;
        pioneer = pioneer->left;
      }
      p->val = pioneer->val;
      if (p == cover) {
        p->right = pioneer->right;
      } else {
        cover->left = pioneer->right;
      }
    }

    return root;
  }
};
