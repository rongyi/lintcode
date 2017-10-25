// http://www.lintcode.com/zh-cn/problem/word-ladder
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::unordered_set;

class Solution {
public:
  /**
   * @param start, a string
   * @param end, a string
   * @param dict, a set of string
   * @return an integer
   1. 将每个单词看成图的一个节点。
   2. 当单词s1改变一个字符可以变成存在于字典的单词s2时，则s1与s2之间有连接。
   3.
   给定s1和s2，问题I转化成了求在图中从s1->s2的最短路径长度。而问题II转化为了求所有s1->s2的最短路径。
  */
  int ladderLength(string start, string end, unordered_set<string> &dict) {
    dict.insert(end);
    std::queue<std::pair<string, int>> q;
    q.push(std::make_pair(start, 1));

    while (!q.empty()) {
      string s = q.front().first;
      int len = q.front().second;
      if (s == end)
        return len;
      q.pop();
      vector<string> neighbors = findNeighbors(s, dict);
      for (int i = 0; i < neighbors.size(); i++) {
        q.push(std::make_pair(neighbors[i], len + 1));
      }
    }
    return 0;
  }

private:
  // 如何找到与当前节点相邻的所有节点?
  // 遍历当前单词的每个字符x，将其改变成a~z中除x外的任意一个，形成一个新的单词，在字典中判断是否存在。复杂度为：26*w，w为单词长度。
  vector<string> findNeighbors(string s, unordered_set<string> &dict) {
    vector<string> ret;
    for (int i = 0; i < s.size(); i++) {
      char c = s[i];
      for (int j = 0; j < 26; j++) {
        if (c == 'a' + j)
          continue;
        s[i] = 'a' + j;
        if (dict.find(s) != dict.end()) {
          ret.push_back(s);
          // duplicate match is not allowed
          dict.erase(s);
        }
      }
      s[i] = c;
    }
    return ret;
  }
};
