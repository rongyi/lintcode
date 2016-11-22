// http://www.lintcode.com/zh-cn/problem/binary-tree-maximum-path-sum

class Solution {
public:
  /**
   * @param root: The root of binary tree.
   * @return: An integer
   */
  int maxPathSum(TreeNode *root) {
    max_sum_ = INT_MIN;
    dfs(root);
    return max_sum_;
  }
private:
  int dfs(const TreeNode *root) {
    if (root == nullptr)
      return 0;
    int l = dfs(root->left);
    int r = dfs(root->right);
    int sum = root->val;
    if (l > 0)
      sum += l;
    if (r > 0)
      sum += r;
    max_sum_ = std::max(max_sum_, sum);

    return std::max(r, l) > 0 ? max(r, l) + root->val : root->val;
  }
private:
  int max_sum_;
};
