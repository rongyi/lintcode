// http://www.lintcode.com/zh-cn/problem/course-schedule-ii
#include <vector>
#include <iostream>
#include <queue>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param numCourses a total of n courses
   * @param prerequisites a list of prerequisite pairs
   * @return the course order
   */
  vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<int> ret;
    vector<vector<int>> graph(numCourses, vector<int>(0));
    vector<int> in(numCourses, 0);
    for (auto &e : prerequisites) {
      graph[e.second].push_back(e.first);
      ++in[e.first];
    }
    queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
      if (in[i] == 0)
        q.push(i);
    }

    while (!q.empty()) {
      int n = q.front();
      ret.push_back(n);
      q.pop();
      for (auto &e : graph[n]) {
        --in[e];
        if (in[e] == 0)
          q.push(e);
      }
    }
    if (ret.size() != numCourses)
      ret.clear();

    return ret;
  }
};
