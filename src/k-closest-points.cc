// http://www.lintcode.com/zh-cn/problem/k-closest-points

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>

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

bool cmp(Point l, Point r) {
  if (l.x < r.x) {
    return true;
  } else if (l.x == r.x) {
    return l.y < r.y;
  }
  return false;
}



class Solution {
public:
  /**
   * @param points a list of points
   * @param origin a point
   * @param k an integer
   * @return the k closest points
   */
  vector<Point> kClosest(vector<Point> &points, Point &origin, int k) {
    // distance point map
    std::unordered_map<uint64_t, std::vector<Point>> dp_dict;
    std::priority_queue<uint64_t, std::vector<uint64_t>, std::greater<int>> pq;
    vector<Point> ret;

    for (auto &p : points) {
      auto d = distance(p, origin);
      if (dp_dict.find(d) == dp_dict.end()) {
        dp_dict[d] = std::vector<Point>{p};
        pq.push(d);
      } else {
        dp_dict[d].push_back(p);
      }
    }

    while (!pq.empty() && k) {
      auto d = pq.top();
      pq.pop();
      auto ps = dp_dict[d];
      // lintcode does not support c++11 lambda, shit
      // if they are same with distance, sorted by x-axis, otherwise sorted by y-axis.
      std::sort(ps.begin(), ps.end(), cmp);
      const int step = std::min(k, int(ps.size()));
      for (int i = 0; i < step; i++) {
        ret.push_back(ps[i]);
        k--;
      }
    }


    return ret;
  }

private:

  uint64_t distance(const Point &p, const Point &origin) {
    const int dx = p.x - origin.x;
    const int dy = p.y - origin.y;
    return dx * dx + dy * dy;
  }
};


int main()
{
  Solution so;
  // vector<Point> ps{Point{4, 6}, Point{4, 7}, Point{4, 4}, Point{2, 5}, Point{1, 1}};
  vector<Point> ps{Point{-435,-347},Point{-435,-347},Point{609,613},Point{-348,-267},Point{-174,-107},Point{87,133},Point{-87,-27},Point{-609,-507},Point{435,453},Point{-870,-747},Point{-783,-667},Point{0,53},Point{-174,-107},Point{783,773},Point{-261,-187},Point{-609,-507},Point{-261,-187},Point{-87,-27},Point{87,133},Point{783,773},Point{-783,-667},Point{-609,-507},Point{-435,-347},Point{783,773},Point{-870,-747},Point{87,133},Point{87,133},Point{870,853},Point{696,693},Point{0,53},Point{174,213},Point{-783,-667},Point{-609,-507},Point{261,293},Point{435,453},Point{261,293},Point{435,453}};
  // Point origin{0, 0};
  Point origin{-11, 199};
  auto ret = so.kClosest(ps, origin, 13);
  for (auto &p : ret) {
    cout << "Point<" << p.x << ", " << p.y << ">" << endl;
  }
  return 0;
}
