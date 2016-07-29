// http://www.lintcode.com/zh-cn/problem/unique-binary-search-trees-ii
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
   * @paramn n: An integer
   * @return: A list of root
   */
  vector<TreeNode *> generateTrees(int n) {
    return do_gen(1, n);
  }
private:

  vector<TreeNode *> do_gen(int ld, int rd) {
    vector<TreeNode *> ret;
    if (ld == rd) {
      TreeNode *tmp = new TreeNode(ld);
      ret.push_back(tmp);
      return ret;
    }
    if (ld > rd) {
      ret.push_back(nullptr);
      return ret;
    }
    for (int i = ld; i <= rd; ++i) {
      vector<TreeNode *> left = do_gen(ld, i - 1);
      vector<TreeNode *> right = do_gen(i + 1, rd);

      for (auto lx : left) {
        for (auto rx : right) {
          TreeNode *tmp = new TreeNode(i);
          tmp->left = lx;
          tmp->right = rx;
          ret.push_back(tmp);
        }
      }
    }
    return ret;
  }
};
