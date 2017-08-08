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
    int untouch_cur = 0;

    do_robber(root, &rob_cur, &untouch_cur);

    return std::max(rob_cur, untouch_cur);
  }
private:
  void do_robber(TreeNode *root, int *rob_cur, int * untouch_cur) {
    if (!root)
      return;

    int rob_cur_left = 0;
    int untouch_cur_left = 0;
    int rob_cur_right = 0;
    int untouch_cur_right = 0;

    do_robber(root->left, &rob_cur_left, &untouch_cur_left);

    do_robber(root->right, &rob_cur_right, &untouch_cur_right);

    *rob_cur = root->val + untouch_cur_left + untouch_cur_right;

    // pick max with no rule
    *untouch_cur = std::max(rob_cur_left, untouch_cur_left) + std::max(rob_cur_right, untouch_cur_right);
  }
};
