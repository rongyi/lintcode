// http://www.lintcode.com/zh-cn/problem/course-schedule-iii

#include <algorithm>
#include <bitset>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /*
   * @param : duration and close day of each course
   * @return: the maximal number of courses that can be taken
   */
  int scheduleCourse(vector<vector<int>> &courses) {
    int cur_time = 0;
    std::priority_queue<int> q;
    std::sort(courses.begin(), courses.end(),
              [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });
    for (auto course : courses) {
      cur_time += course[0];
      q.push(course[0]);
      if (cur_time > course[1]) {
        cur_time -= q.top();
        q.pop();
      }
    }
    return q.size();
  }
};

int main()
{
  Solution so;
  vector<vector<int>> test{{100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200}};
  auto ret = so.scheduleCourse(test);

  cout << ret << endl;
  return 0;
}
