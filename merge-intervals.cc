// http://www.lintcode.com/zh-cn/problem/merge-intervals
#include <vector>
#include <algorithm>
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
public:
  int start, end;
  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

bool cmp(const Interval &a, const Interval &b) {
  if (a.start == b.start)
    return a.end < b.end;
  return a.start < b.start;
}

class Solution {
public:
  /**
   * @param intervals: interval list.
   * @return: A new interval list.
   */
  vector<Interval> merge(vector<Interval> &intervals) {
    if (intervals.empty())
      return intervals;
    std::sort(intervals.begin(), intervals.end(), cmp);
    for (int i = 1; i < intervals.size(); i++) {
      if (intervals[i - 1].end >= intervals[i].start) {
        if (intervals[i - 1].end < intervals[i].end) {
          intervals[i - 1].end = intervals[i].end;
        }
        intervals.erase(intervals.begin() + i);
        --i;
      }
    }
    return intervals;
  }
};
