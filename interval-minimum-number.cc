// http://www.lintcode.com/zh-cn/problem/interval-minimum-number
#include <vector>
#include <iostream>
#include <string>

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
  int start, end;
  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class SegmentTreeNode {
public:
  int start, end, ;
  SegmentTreeNode *left, *right;
  SegmentTreeNode(int start, int end) {
    this->start = start, this->end = end;
    this->left = this->right = NULL;
  }
};

class Solution {
public:
  /**
   *@param A, queries: Given an integer array and an query list
   *@return: The result list
   */
  vector<int> intervalMinNumber(vector<int> &a, vector<Interval> &queries) {
    // write your code here
  }
};
