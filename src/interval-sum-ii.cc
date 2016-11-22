// http://www.lintcode.com/zh-cn/problem/interval-sum-ii
#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:

  class SegmentTreeNode {
  public:
    int start, end;
    long long sum;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int start, int end, long long sum=0) {
      this->start = start, this->end = end;
      this->left = this->right = nullptr;
      this->sum = sum;
    }
  };

  /**
   * @param A: An integer vector
   */
  Solution(vector<int> A) : root_(nullptr) {
    aux_ = A;
    if (A.size())
      root_ = build(0, A.size() - 1);
  }

  /**
   * @param start, end: Indices
   * @return: The sum from start to end
   */
  long long query(int start, int end) {
    return query(root_, start, end);
  }

  long long query(SegmentTreeNode *root, int start, int end) {
    if (root->start == start && root->end == end) {
      return root->sum;
    }

    const int mid = root->start + (root->end - root->start) / 2;
    if (end <= mid) {
      return query(root->left, start, end);
    } else if (start > mid) {
      return query(root->right, start, end);
    } else {
      return query(root->left, start, mid) +
        query(root->right, mid + 1, end);
    }
  }

  /**
   * @param index, value: modify A[index] to value.
   */
  void modify(int index, int value) {
    if (index < 0 || index >= aux_.size())
      return;

    modify(root_, index, value);
  }

  int modify(SegmentTreeNode *root, int index, int new_value) {
    if (root->start == root->end && index == root->start) {
      auto diff = new_value - root->sum;
      root->sum = new_value;
      return diff;
    }

    const int mid = root->start + (root->end - root->start) / 2;
    int diff = 0;
    if (index <= mid)
      diff = modify(root->left, index, new_value);
    else
      diff = modify(root->right, index, new_value);
    root->sum += diff;

    return diff;
  }

  SegmentTreeNode * build(int start, int end) {
    if (start > end) {
      return nullptr;
    }

    if (start == end) {
      return new SegmentTreeNode(start, end, aux_[start]);
    }
    SegmentTreeNode *root = new SegmentTreeNode(start, end);
    const int mid = start + (end - start) / 2;
    root->left = build(start, mid);
    root->right = build(mid + 1, end);
    root->sum = root->left->sum + root->right->sum;

    return root;
  }
private:
  vector<int> aux_;
  SegmentTreeNode *root_;
};
