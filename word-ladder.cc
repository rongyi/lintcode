// http://www.lintcode.com/zh-cn/problem/word-ladder
#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <queue>

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
          dict.erase(s);
        }
      }
      s[i] = c;
    }
    return ret;
  }
};
