// http://www.lintcode.com/zh-cn/problem/house-robber-iii
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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  /**
   * @param root: The root of binary tree.
   * @return: The maximum amount of money you can rob tonight
   */
  int houseRobber3(TreeNode* root) {
    if (!root)
      return 0;
    int rob_cur = 0;
    int rob_cur_not = 0;

    do_robber(root, &rob_cur, &rob_cur_not);

    return std::max(rob_cur, rob_cur_not);
  }
private:
  void do_robber(TreeNode *root, int *rob_cur, int * rob_cur_not) {
    if (!root)
      return;

    int rob_cur_left = 0;
    int rob_cur_left_not = 0;
    int rob_cur_right = 0;
    int rob_cur_right_not = 0;

    do_robber(root->left, &rob_cur_left, &rob_cur_left_not);

    do_robber(root->right, &rob_cur_right, &rob_cur_right_not);

    *rob_cur = root->val + rob_cur_left_not + rob_cur_right_not;

    // pick max with no rule
    *rob_cur_not = std::max(rob_cur_left, rob_cur_left_not) + std::max(rob_cur_right, rob_cur_right_not);
  }
};
