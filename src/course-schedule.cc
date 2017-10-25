// http://www.lintcode.com/zh-cn/problem/course-schedule
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
  /**
   * @param numCourses a total of n courses
   * @param prerequisites a list of prerequisite pairs
   * @return true if can finish all courses or false
   */
  bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites) {
    vector<vector<int>> graph(numCourses, vector<int>(0));
    vector<int> in(numCourses, 0);

    for (auto a : prerequisites) {
      graph[a.second].push_back(a.first);
      ++in[a.first];
    }

    std::queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
      if (in[i] == 0) {
        q.push(i);
      }
    }

    while (!q.empty()) {
      int n = q.front();
      q.pop();
      for (auto &e : graph[n]) {
        --in[e];
        if (in[e] == 0)
          q.push(e);
      }
    }

    for (int i = 0; i < numCourses; ++i) {
      if (in[i] != 0)
        return false;
    }

    return true;
  }
};
