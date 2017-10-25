// http://www.lintcode.com/zh-cn/problem/segment-tree-query-ii
#include <climits>

// Definition of SegmentTreeNode:
class SegmentTreeNode {
public:
  int start, end, count;
  SegmentTreeNode *left, *right;
  SegmentTreeNode(int start, int end, int count) {
    this->start = start;
    this->end = end;
    this->count = count;
    this->left = this->right = nullptr;
  }
};

class Solution {
public:
  /**
   *@param root, start, end: The root of segment tree and
   *                         an segment / interval
   *@return: The count number in the interval [start, end]
   */
  int query(SegmentTreeNode *root, int start, int end) {
    if (!root || start > end)
      return 0;

    if (root->start > end || root->end < start) {
      return 0;
    }

    if (root->start >= start && root->end <= end)
      return root->count;

    return query(root->left, start, end) + query(root->right, start, end);
  }
};
