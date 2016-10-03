// http://www.lintcode.com/zh-cn/problem/segment-tree-modify
/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class SegmentTreeNode {
public:
  int start, end, max;
  SegmentTreeNode *left, *right;
  SegmentTreeNode(int start, int end, int max) {
    this->start = start;
    this->end = end;
    this->max = max;
    this->left = this->right = nullptr;
  }
};

class Solution {
public:
  /**
   *@param root, index, value: The root of segment tree and
   *@ change the node's value with [index, index] to the new given value
   *@return: void
   */
  void modify(SegmentTreeNode *root, int index, int value) {
    // write your code here
  }
};
