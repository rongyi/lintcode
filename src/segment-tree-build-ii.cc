// http://www.lintcode.com/zh-cn/problem/segment-tree-build-ii
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::string;

/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 * int start, end, max;
 * SegmentTreeNode *left, *right;
 * SegmentTreeNode(int start, int end, int max) {
 * this->start = start;
 * this->end = end;
 * this->max = max;
 * this->left = this->right = NULL;
 * }
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
   *@param A: a list of integer
   *@return: The root of Segment Tree
   */
  SegmentTreeNode * build(vector<int>& nums) {
    if (nums.empty())
      return nullptr;

    return build(nums, 0, nums.size() - 1);
  }
  SegmentTreeNode *build(vector<int> &nums, int start, int end) {
    if (start > end)
      return nullptr;
    if (start == end) {
      return new SegmentTreeNode(start, start, nums[start]);
    }

    SegmentTreeNode *root = new SegmentTreeNode(start, end, std::numeric_limits<int>::min());
    const int mid = start + (end - start) / 2;
    root->left = build(nums, start, mid);
    root->right = build(nums, mid + 1, end);
    root->max = std::max(root->left->max,
                         root->right->max);

    return root;
  }
};
