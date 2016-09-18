// http://www.lintcode.com/zh-cn/problem/lowest-common-ancestor
#include <vector>
#include <iostream>
#include <string>

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
   * @param root: The root of the binary search tree.
   * @param a and b: two nodes in a Binary.
   * @return: Return the least common ancestor(LCA) of the two nodes.
   */
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *a, TreeNode *b) {
    if (!root || !a || !b)
      return nullptr;

    if (a->left == b || a->right == b || a->val == root->val) {
      return a;
    } else if (b->left == a || b->right == a || b->val == root->val) {
      return b;
    } else if (a->val < root->val && b->val < root->val) {
      return lowestCommonAncestor(root->left, a, b);
    } else if (a->val > root->val && b->val > root->val) {
      return lowestCommonAncestor(root->right, a, b);
    } else if ((a->val < root->val && b->val > root->val) ||
               (b->val < root->val && a->val > root->val)) {
      return root;
    } else {
      return nullptr;
    }
  }
};

int main()
{
  Solution so;
  TreeNode t1(-2);
  TreeNode t2(-1);
  TreeNode t3(-3);
  t1.left = &t2;
  t1.right = &t3;

  auto ret = so.lowestCommonAncestor(&t1, &t2, &t3);
  cout << ret->val << endl;

  return 0;
}
