// http://www.lintcode.com/zh-cn/problem/minimum-window-substring
#include <string>
#include <unordered_map>
#include <algorithm>

using std::string;
using std::unordered_map;

class Solution {
public:
  /**
   * @param source: A string
   * @param target: A string
   * @return: A string denote the minimum window
   *          Return "" if there is no such a string
   */
  string minWindow(string &source, string &target) {
    unordered_map<char, int> mark;
    unordered_map<char, int> check;
    for (auto t : target)
      ++mark[t];
    int begin = 0;
    int end = 0;
    const int n = source.length();
    int min = std::numeric_limits<int>::max();
    string ret;

    for (; end < n; ++end) {
      if (mark.find(source[end]) != mark.end())
        ++check[source[end]];
      while (every(check, mark)) {
        const int cur_len = end - begin + 1;
        if (cur_len < min) {
          min = cur_len;
          ret = source.substr(begin, cur_len);
        }
        --check[source[begin]];
        ++begin;
      }
    }
    return min == std::numeric_limits<int>::max() ? "" : ret;
  }

private:
  bool every(unordered_map<char, int> &check, unordered_map<char, int> &mark) {
    for (auto m : mark) {
      if (check[m.first] < m.second)
        return false;
    }

    return true;
  }
};
