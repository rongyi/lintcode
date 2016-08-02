// http://www.lintcode.com/zh-cn/problem/word-break
#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::unordered_set;

class Solution {
public:
  /**
   * @param s: A string s
   * @param dict: A dictionary of words dict
   */
  bool wordBreak(string s, unordered_set<string> &dict) {
    if (s.empty())
      return true;
    if (dict.empty())
      return false;
    for (auto & cur: dict) {
      if (cur.empty())
        continue;
      if (s.find(cur) != std::string::npos)
        return true;
    }
    return false;
  }
};

int main()
{
  Solution so;
  unordered_set<string> test_set;
  test_set.insert("lint");
  test_set.insert("code");
  auto s = std::string("lintcode");
  auto ret = so.wordBreak(s, test_set);

  cout << ret << endl;
  return 0;
}
