// http://www.lintcode.com/zh-cn/problem/two-sum-bst-edtion
#include <iostream>
#include <string>
#include <vector>

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
  */
  vector<int> twoSum(TreeNode *root, int n) {

  }
};
