// http://www.lintcode.com/zh-cn/problem/word-ladder-ii
#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <queue>
#include <unordered_map>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::unordered_set;
using std::queue;
using std::unordered_map;

class Solution {
public:
  /**
   * @param start, a string
   * @param end, a string
   * @param dict, a set of string
   * @return a list of lists of string
   如果要返回所有的结果，问题变复杂了些。因为用BFS相对于DFS的劣势就是不方便存储结果。这种需要返回所有结果的，还是应该从DFS考虑，但是直接应用DFS复杂
   度会很高，因为这道题我们只要知道结尾就好了，不用继续往下搜。

   所以问题就转化成怎样用DFS的同时又可以限制DFS的深度，所以我们可以BFS与DFS结合。先用BFS搜到结尾字符串，然后把中途所有的字符串及其跟起始字符的
   edit distance存在一个map里。这样的话，我们就可以从结尾字符串开始DFS，只有Map内的字符串才考虑继续DFS，直至搜到起始字符。

   注意这里有个小技巧，就是为什么不从起始字符串开始DFS直至搜到结尾字符串，而是反过来。这里可以脑子里想像一个图，如果从起始字符串开始搜，
   到最后一层的话会有很多无效搜索，因为那层我们只需要找到结尾字符串，那么多无效的搜索到最一层太浪费时间。反之，如果我们从结尾字符串开始DFS,
   我们把起始层控制在一个字符串，整个图先越来越宽，然后越来越窄直到起始字符串，而非一直越来越宽直到结尾字符串那层。
  */
  vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
    unordered_map<string, int> distance_map;
    mkDistanceMap(start, end, dict, distance_map);
    vector<vector<string>> ret;
    vector<string> cur;

    dfs(ret, cur, distance_map, end, start);

    return ret;
  }
private:
  void dfs(vector<vector<string>> &ret, vector<string> &cur,
           unordered_map<string, int> &distance_map,
           string &start, string &end) {

    if (start == end) {
      vector<string> vec = cur;
      vec.push_back(end);
      std::reverse(vec.begin(), vec.end());
      ret.push_back(vec);

      return;
    }
    cur.push_back(start);
    // a shadow start
    string starts = start;
    for (unsigned i = 0; i < starts.size(); i++) {
      char c = starts[i];
      for (int j = 0; j < 26; j++) {
        starts[i] = 'a' + j;
        if (distance_map.find(starts) != distance_map.end() &&
            distance_map[starts] == distance_map[start] - 1) {
          dfs(ret, cur, distance_map, starts, end);
        }
      }
      starts[i] = c;
    }

    cur.pop_back();
  }
  void mkDistanceMap(string start, string end, unordered_set<string> &dict, unordered_map<string, int> &distance_map) {
    distance_map.insert(std::make_pair(start, 1));
    queue<string> q;
    q.push(start);

    while (!q.empty()) {
      string s = q.front();
      q.pop();

      string s2 = s;

      for (unsigned i = 0; i < s2.size(); i++) {
        char c = s2[i];
        for (int j = 0; j < 26; j++) {
          s2[i] = 'a' + j;

          if (s2 == end) {
            distance_map.insert(std::make_pair(s2, distance_map[s] + 1));
            return;
          }
          if (dict.find(s2) != dict.end() && distance_map.find(s2) == distance_map.end()) {
            q.push(s2);
            distance_map.insert(std::make_pair(s2, distance_map[s] + 1));
          }
        }

        // restore
        s2[i] = c;
      }
    }
  }
};

int main()
{
  Solution so;
  string start("hot");
  string end("dog");
  unordered_set<string> dict{"hot","cog","dog","tot","hog","hop","pot","dot"};
  auto ret = so.findLadders(start, end, dict);
  for (auto v : ret) {
    for (auto s : v)
      cout << s << " ";
    cout << endl;
  }

  return 0;
}
