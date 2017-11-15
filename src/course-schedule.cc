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

    // "要学习课程 0 你需要先学习课程 1 ，表示为[0,1]"
    // 单向图表示从1到0有边，in表示节点的入度
    for (auto a : prerequisites) {
      graph[a.second].push_back(a.first);
      ++in[a.first];
    }

    // 搜集没有依赖的课程，从这些没有依赖的课程找出去
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
        // 修完这门课程
        --in[e];
        // 假设这也是一门没有依赖的课程，从这里开始找出去
        if (in[e] == 0)
          q.push(e);
      }
    }

    // 发现入度还有为1的课程则这门课完成不了
    for (int i = 0; i < numCourses; ++i) {
      if (in[i] != 0)
        return false;
    }

    return true;
  }
};
