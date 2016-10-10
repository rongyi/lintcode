// http://www.lintcode.com/zh-cn/problem/count-of-smaller-number-before-itself
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
    int smaller_count;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int start, int end, int smaller_count=0) {
      this->start = start, this->end = end;
      this->left = this->right = nullptr;
      this->smaller_count = smaller_count;
    }
  };

  Solution() {
    root_ = build(0, 20000);
  }
  ~Solution() {
    //TODO
  }
  /**
   * @param A: An integer array
   * @return: Count the number of element before this element 'ai' is
   *          smaller than it and return count number array
   */
  vector<int> countOfSmallerNumberII(vector<int> &A) {
    vector<int> ret;
    for (auto i : A) {
      auto count = query(root_, 0, i - 1);
      ret.push_back(count);
      modify(root_, i);
    }
    return ret;
  }

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

  void modify(SegmentTreeNode *root, int index) {
    if (!root)
      return;
    if (root->start == root->end && index == root->start) {
      ++(root->smaller_count);
      return;
    }

    const int mid = root->start + (root->end - root->start) / 2;

    if (index <= mid)
      modify(root->left, index);
    else
      modify(root->right, index);

    root->smaller_count = root->left->smaller_count + (root->right ? root->right->smaller_count : 0);
  }

  int query(SegmentTreeNode *root, int start, int end) {
    if (start > root->end || end < root->start)
      return 0;

    if (root->start == start && root->end == end) {
      return root->smaller_count;
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

private:
  void free(SegmentTreeNode *root) {
    if (!root)
      return;
    if (!root->left && !root->right) {
      delete root;
      root = nullptr;
    }

    if (root->left) {
      delete root->left;
      root->left = nullptr;
    }

    if (root->right) {
      delete root->right;
      root->right = nullptr;
    }
  }
  SegmentTreeNode *root_;
};

int main()
{
  Solution so;
  vector<int> test{73,82,74,12,25,0,33,46,79,90,6,97,18,84,34,54,64,5,54,44,74,95,90,24,70,94,12,41,79,88,48,82,89,100,33,3,23,21,90,50,26,3,4,21,67,24,59,62,9,78,60,40,4,40,7,5,54,38,68,66};
  so.countOfSmallerNumberII(test);
  return 0;
}
