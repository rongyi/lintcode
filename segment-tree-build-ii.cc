// http://www.lintcode.com/zh-cn/problem/segment-tree-build-ii
#include <vector>
#include <iostream>
#include <string>

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
    this->left = this->right = NULL;
  }
};

class Solution {
public:
  /**
   *@param A: a list of integer
   *@return: The root of Segment Tree
   */
  SegmentTreeNode * build(vector<int>& A) {

  }
};
