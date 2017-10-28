// http://www.lintcode.com/zh-cn/problem/bst-swapped-nodes
#include <bitset>
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
    this->left = this->right = nullptr;
  }
};

class Solution {
public:
  /*
  * @param : the given tree
  * @return: the tree after swapping
  * http://www.geeksforgeeks.org/fix-two-swapped-nodes-of-bst/
  */
  TreeNode *bstSwappedNode(TreeNode *root) {
    TreeNode *first = nullptr;
    TreeNode *middle = nullptr;
    TreeNode *last = nullptr;
    TreeNode *prev = nullptr;

    recur(root, &first, &middle, &last, &prev);
    if (first && last) {
      swap(&(first->val), &(last->val));
    } else if (first && middle) {
      swap(&(first->val), &(middle->val));
    }

    return root;
  }

  void recur(TreeNode *root, TreeNode **first, TreeNode **middle,
             TreeNode **last, TreeNode **prev) {
    if (!root) {
      return;
    }
    recur(root->left, first, middle, last, prev);

    // two cases
    // 1. swap node is not adjacent
    // 2. swap node is adjacent
    if (*prev && root->val < (*prev)->val) {
      if (!*first) {
        *first = *prev;
        *middle = root;
      } else {
        *last = root;
      }
    }
    *prev = root;

    recur(root->right, first, middle, last, prev);
  }

  void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
  }
};

int main() {
  Solution so;
  TreeNode n1(1), n2(2), n3(3), n4(4), n5(5);
  n4.left = &n5;
  n4.right = &n2;
  n2.left = &n1;
  n2.right = &n3;

  so.bstSwappedNode(&n4);

  return 0;
}
