// http://www.lintcode.com/zh-cn/problem/two-sum-bst-edtion
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

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
public:
  /*
  * @param : the root of tree
  * @param : the target sum
  * @return: two number from tree witch sum is n
  * the question says: Without any extra space. this is shit!
  */
  vector<int> twoSum(TreeNode *root, int n) {
    std::vector<int> ret;
    if (!root) {
      return ret;
    }
    std::unordered_set<int> s;
    rec(root, n, s, ret);
    if (ret.size() > 2) {
      ret.resize(2);
    }
    return ret;
  }
  void rec(TreeNode *node, int t, std::unordered_set<int> &s, std::vector<int> &ret) {
    if (!node) {
      return;
    }
    if (s.find(t - node->val) != s.end()) {
      ret.push_back(node->val);
      ret.push_back(t - node->val);
      return;
    }
    s.insert(node->val);
    rec(node->left, t, s, ret);
    rec(node->right, t, s, ret);
  }
};
