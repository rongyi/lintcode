// http://www.lintcode.com/zh-cn/problem/subtree
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
   * @param T1, T2: The roots of binary tree.
   * @return: True if T2 is a subtree of T1, or false.
   */
  bool isSubtree(TreeNode *t1, TreeNode *t2) {
    // this version is a bst version
    // if (t2 == nullptr)
    //   return true;

    // if (!t1)
    //   return false;

    // if (t1->val < t2->val) {
    //   return isSubtree(t1->right, t2);
    // } else if (t1->val > t2->val) {
    //   return isSubtree(t1->left, t2);
    // } else {
    //   // not left
    //   if (t1->left == nullptr && t2->left == nullptr) {
    //     return isSubtree(t1->right, t2->right);
    //   } else if (t1->right == nullptr && t2->right == nullptr) { // no right
    //     return isSubtree(t1->left, t2->left);
    //   } else if (t1->left && t2->left && t1->right && t2->right) { // has all
    //     return isSubtree(t1->left, t2->left) && isSubtree(t1->right,
    //     t2->right);
    //   }
    //   return false;
    // }

    ret_ = false;
    dfs(t1, t2);
    return ret_;
  }

private:
  bool check(TreeNode *t1, TreeNode *t2) {
    if (t1 == nullptr && t2 != nullptr)
      return false;
    if (t1 != nullptr && t2 == nullptr)
      return false;
    if (t1 == nullptr && t2 == nullptr)
      return true;

    if (t1->val != t2->val)
      return false;
    return check(t1->left, t2->left) && check(t1->right, t2->right);
  }

  void dfs(TreeNode *t1, TreeNode *t2) {
    if (check(t1, t2)) {
      ret_ = true;
      return;
    }
    if (t1 == nullptr)
      return;

    dfs(t1->left, t2);
    dfs(t1->right, t2);
  }

private:
  bool ret_;
};
