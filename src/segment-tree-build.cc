// http://www.lintcode.com/zh-cn/problem/segment-tree-build
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;


class SegmentTreeNode {
public:
  int start, end;
  SegmentTreeNode *left, *right;
  SegmentTreeNode(int start, int end) {
    this->start = start, this->end = end;
    this->left = this->right = NULL;
  }
};


class Solution {
public:
  /**
   *@param start, end: Denote an segment / interval
   *@return: The root of Segment Tree
   */
  SegmentTreeNode * build(int start, int end) {
    if (start > end) {
      return nullptr;
    }
    if (start == end) {
      return new SegmentTreeNode(start, end);
    }
    SegmentTreeNode *root = new SegmentTreeNode(start, end);
    const int mid = start + (end - start) / 2;
    root->left = build(start, mid);
    root->right = build(mid + 1, end);

    return root;
  }

};
