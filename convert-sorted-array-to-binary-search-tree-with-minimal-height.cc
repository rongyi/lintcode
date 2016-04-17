// http://www.lintcode.com/zh-cn/problem/convert-sorted-array-to-binary-search-tree-with-minimal-height

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
class Solution {
public:
  /**
   * @param A: A sorted (increasing order) array
   * @return: A tree node
   */
  TreeNode *sortedArrayToBST(vector<int> &A) {
    return sortedArrayToBST(A.begin(), A.end());
  }
  template<typename RandomAccessIterator>
  TreeNode *sortedArrayToBST(RandomAccessIterator first, RandomAccessIterator last) {
    const auto length = distance(first, last);
    if (length <= 0)
      return nullptr;
    auto mid = first + length / 2;
    TreeNode *root = new TreeNode(*mid);
    root->left = sortedArrayToBST(first, mid);
    root->right = sortedArrayToBST(mid + 1, last);

    return root;
  }

};
