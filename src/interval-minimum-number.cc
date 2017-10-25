// http://www.lintcode.com/zh-cn/problem/interval-minimum-number
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Interval;
class SegmentTreeNode;

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */

class Interval {
public:
  int start, end;
  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class Solution {
public:
  /**
   *@param A, queries: Given an integer array and an query list
   *@return: The result list
   */
  class SegmentTreeNode {
  public:
    int start, end, min;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int start, int end,
                    int min = std::numeric_limits<int>::max()) {
      this->start = start, this->end = end;
      this->left = this->right = nullptr;
      this->min = min;
    }
  };
  vector<int> intervalMinNumber(vector<int> &a, vector<Interval> &queries) {
    vector<int> ret;
    if (a.empty())
      return ret;

    SegmentTreeNode *root = build(0, a.size() - 1, a);
    for (auto interval : queries) {
      auto cur_ret = query(root, interval.start, interval.end);
      ret.push_back(cur_ret);
    }
    return ret;
  }

  // FIXME: add free function
  SegmentTreeNode *build(int start, int end, const vector<int> &input) {
    if (start > end) {
      return nullptr;
    }
    if (start == end) {
      return new SegmentTreeNode(start, end, input[start]);
    }
    SegmentTreeNode *root = new SegmentTreeNode(start, end);
    const int mid = start + (end - start) / 2;
    root->left = build(start, mid, input);
    root->right = build(mid + 1, end, input);
    root->min = std::min(root->left->min, root->right->min);

    return root;
  }

  int query(SegmentTreeNode *root, int start, int end) {
    if (root->start == start && root->end == end) {
      return root->min;
    }
    const int mid = root->start + (root->end - root->start) / 2;
    if (end <= mid) {
      return query(root->left, start, end);
    } else if (start > mid) {
      return query(root->right, start, end);
    } else {
      return std::min(query(root->left, start, mid),
                      query(root->right, mid + 1, end));
    }
  }
};

int main() {
  Solution so;
  vector<int> test{1, 2, 7, 8, 5};
  vector<Interval> query;
  query.push_back(Interval(1, 2));

  auto ret = so.intervalMinNumber(test, query);
  for (auto i : ret)
    cout << i << endl;
  return 0;
}
