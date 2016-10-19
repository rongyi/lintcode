// http://www.lintcode.com/zh-cn/problem/max-points-on-a-line
#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;


/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
public:
  /**
   * @param points an array of point
   * @return an integer
   */
  int maxPoints(vector<Point>& points) {

  }

private:
  struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
  };
};
