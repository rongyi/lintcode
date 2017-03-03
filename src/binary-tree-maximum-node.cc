#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

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
   * @param root the root of binary tree
   * @return the max node
   */
  TreeNode* maxNode(TreeNode* root) {
    if (!root) {
      return nullptr;
    }
    // do not using pointer of pointer
    TreeNode *retl = root;
    TreeNode *retr = root;
    rec(root->left, &retl);
    rec(root->right, &retr);

    return retl->val > retr->val ? retl : retr;
  }

  void rec(TreeNode *root, TreeNode **ret) {
    if (!root)
      return;
    if (root->val > (*ret)->val) {
      *ret = root;
    }
    rec(root->left, ret);

    rec(root->right, ret);
  }
};

int main()
{
  TreeNode n1(1), n5(-5), n0(0), n3(3);
  n1.left = &n5;
  n5.left = &n0;
  n5.right = &n3;
  Solution so;
  auto ret = so.maxNode(&n1);
  return 0;
}
