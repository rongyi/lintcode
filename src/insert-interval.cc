// http://www.lintcode.com/zh-cn/problem/insert-interval
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::sort;


class Interval {
public:
  int start, end;
  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

bool comp(Interval a, Interval b) {
  return a.start < b.start;
}
class Solution {
public:
  /**
   * Insert newInterval into intervals.
   * @param intervals: Sorted interval list.
   * @param newInterval: new interval.
   * @return: A new interval list.
   */
  vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    intervals.insert(intervals.end(), newInterval);
    sort(intervals.begin(), intervals.end(), comp);
    int len = intervals.size();
    vector<Interval> res;
    int i;
    for (i = 1; i < len; ++i) {
      while (intervals[i].start <= intervals[i-1].end && i < len) {
        intervals[i].start = intervals[i-1].start;
        intervals[i].end = intervals[i].end > intervals[i-1].end ?
          intervals[i].end : intervals[i-1].end;
        i++;
      }
      res.push_back(intervals[i-1]);
      if (i >= len) {
        return res;
      }
    }
    // now intersection
    res.push_back(intervals[i-1]);
    return res;
  }

};


int main(int argc, char *argv[])
{
  Solution so;
  vector<Interval> test{Interval(1, 2), Interval(5, 9)};
  auto ret = so.insert(test, Interval(7, 100));
  cout << ret.size() << endl;
  return 0;
}
