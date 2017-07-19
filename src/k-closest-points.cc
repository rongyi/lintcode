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

struct Point {
  int x;
  int y;
  Point() : x(0), y(0) {}
  Point(int a, int b) : x(a), y(b) {}
};



class Solution {
public:
  /**
   * @param points a list of points
   * @param origin a point
   * @param k an integer
   * @return the k closest points
   */
  vector<Point> kClosest(vector<Point>& points, Point& origin, int k) {
    // Write your code here
  }
};
