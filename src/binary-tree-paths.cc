// http://www.lintcode.com/zh-cn/problem/binary-tree-paths/
class Solution {
public:
  vector<string> binaryTreePaths(TreeNode *root) {
    // vector<string> ret;
    // help(root, "", ret);
    // return ret;
    auto ret = __binaryTreePaths(root);
    vector<string> str_ret;
    for (auto &vec : ret) {
      stringstream ss;
      for (int i = 0; i < vec.size(); i++) {
        ss << vec[i];
        if (i != vec.size() - 1)
          ss << "->";
      }
      str_ret.push_back(ss.str());
    }

    return str_ret;
  }

private:
  /**
   * @param root the root of the binary tree
   * @return all root-to-leaf paths
   */
  vector<vector<int>> __binaryTreePaths(TreeNode *root) {
    vector<vector<int>> ret;
    vector<int> cur;
    help(root, cur, ret);
    return ret;
  }
  void help(TreeNode *root, vector<int> &cur, vector<vector<int>> &ret) {
    if (!root)
      return;
    cur.push_back(root->val);
    if (root->left == nullptr && root->right == nullptr) {
      ret.push_back(cur);
    }
    if (root->left)
      help(root->left, cur, ret);
    if (root->right)
      help(root->right, cur, ret);
    cur.pop_back();
  }
};
