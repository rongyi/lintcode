// http://www.lintcode.com/zh-cn/problem/max-points-on-a-line
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
struct Point {
  int x;
  int y;
  Point() : x(0), y(0) {}
  Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
  /**
   * @param points an array of point
   * @return an integer
   */
  int maxPoints(vector<Point> &points) {
    if (points.size() < 3)
      return points.size();
    int ret = 0;

    unordered_map<double, int> slope_count;
    for (int i = 0; i < points.size() - 1; i++) {
      slope_count.clear();

      // 重合在一个点的个数
      int same_count = 0;
      // 共线的个数
      int same_line_count = 1;
      for (int j = i + 1; j < points.size(); j++) {
        double slope;
        if (points[i].x == points[j].x) {
          if (points[i].y == points[j].y) {
            ++same_count;
            continue;
          }
          slope = std::numeric_limits<double>::infinity();
        } else {
          slope =
              1.0 * (points[i].y - points[j].y) / (points[i].x - points[j].x);
        }

        int count = 0;
        if (slope_count.find(slope) != slope_count.end()) {
          count = ++slope_count[slope];
        } else {
          count = 2;
          slope_count[slope] = 2;
        }

        same_line_count = std::max(same_line_count, count);
      }

      ret = std::max(ret, same_line_count + same_count);
    }
    return ret;
  }
};
