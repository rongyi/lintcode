// http://www.lintcode.com/zh-cn/problem/segment-tree-query
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using std::vector;
using std::cout;
using std::endl;


class SegmentTreeNode {
public:
  int start, end, max;
  SegmentTreeNode *left, *right;
  SegmentTreeNode(int start, int end, int max) {
    this->start = start;
    this->end = end;
    this->max = max;
    this->left = this->right = NULL;
  }
};


class Solution {
public:
  /**
   *@param root, start, end: The root of segment tree and
   *                         an segment / interval
   *@return: The maximum number in the interval [start, end]
   */
  int query(SegmentTreeNode *root, int start, int end) {
    if (!root || start > end)
      return INT_MIN;

    if(root->start > end || root->end < start) {
      return INT_MIN;
    }

    if(root->start >= start && root->end <= end)
      return root->max;

    const int mid = root->start + (root->end - root->start) / 2;

    int leftmax = query(root->left, start, std::min(mid, end));
    int rightmax = query(root->right, std::max(mid, start), end);
    return std::max(leftmax, rightmax);
  }
};
