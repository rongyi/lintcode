// http://www.lintcode.com/zh-cn/problem/split-string
#include <vector>
#include <iostream>
#include <string>
#include <bitset>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /*
  * @param : a string to be split
  * @return: all possible split string array
  */
  vector<vector<string>> splitString(string& s) {
    vector<vector<string>> ret;
    vector<string> cur;
    rec(s, s.length(), 0, ret, cur);

    return ret;
  }

  void rec(const string &s, const int len, int i, vector<vector<string>> &ret, vector<string> &cur) {
    if (i >= len) {
      vector<string> tmp = cur;
      ret.push_back(tmp);
      return;
    }

    cur.push_back(s.substr(i, 1));
    rec(s, len, i + 1, ret, cur);
    cur.pop_back();

    if (i + 2 <= len) {
      cur.push_back(s.substr(i, 2));
      rec(s, len, i + 2, ret, cur);
      cur.pop_back();
    }
  }
};

int main()
{
  Solution so;
  string s = "123";
  auto ret = so.splitString(s);
  for (auto ss: ret) {
    for (auto s : ss) {
      cout << s << "  ";
    }
    cout << endl;
  }

  return 0;
}
