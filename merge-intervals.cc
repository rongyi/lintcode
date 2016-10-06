// http://www.lintcode.com/zh-cn/problem/merge-intervals
#include <vector>
using std::vector;
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
class Solution {
public:
  /**
   * @param intervals: interval list.
   * @return: A new interval list.
   */
  vector<Interval> merge(vector<Interval> &intervals) {
    // write your code here
  }
};
