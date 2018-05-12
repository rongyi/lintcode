// http://www.lintcode.com/zh-cn/problem/binary-tree-longest-consecutive-sequence
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
    this->left = this->right = nullptr;
  }
};


class Solution {
public:
  /**
   * @param root: the root of binary tree
   * @return: the length of the longest consecutive sequence path
   */
  int longestConsecutive(TreeNode *root) {
    if (!root) {
      return 0;
    }
    int ret = 0;
    dfs(root, root->val, 0, ret);
    return ret;
  }

private:
  void dfs(TreeNode *node, int v, int cur, int &ret) {
    if (!node) {
      return;
    }
    if (node->val == (v + 1)) {
      ++cur;
    } else {
      cur = 1;
    }
    ret = std::max(ret, cur);
    dfs(node->left, node->val, cur, ret);
    dfs(node->right, node->val, cur, ret);
  }
};
