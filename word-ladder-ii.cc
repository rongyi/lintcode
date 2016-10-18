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
   */
  vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
    unordered_map<string, int> distance_map;
    mkDistanceMap(start, end, dict, distance_map);
    vector<vector<string>> ret;
    vector<string> cur;

    dfs(ret, cur, distance_map, dict, end, start);

    return ret;
  }
private:
  void dfs(vector<vector<string>> &ret, vector<string> &cur,
           unordered_map<string, int> &distance_map,
           unordered_set<string> &dict,
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
          dfs(ret, cur, distance_map, dict, starts, end);
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
