// http://www.lintcode.com/zh-cn/problem/palindrome-partitioning
#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param s: A string
   * @return: A list of lists of string
   */
  vector<vector<string>> partition(string s) {
    vector<vector<string>> ret;
    vector<string> tmp;
    help(ret, s, tmp);

    return ret;
  }

public:
  void help(vector<vector<string>> &ret, string s, vector<string> &tmp) {
    if (s.empty()) {
      ret.push_back(tmp);
      return;
    }
    for (int i = 1; i <= s.size(); i++) {
      string cur = s.substr(0, i);
      if (isParlidrome(cur)) {
        tmp.push_back(cur);
        help(ret, s.substr(i), tmp);
        tmp.pop_back();
      }
    }
  }

  bool isParlidrome(const string s) {
    if (s.empty() || s.size() == 1) {
      return true;
    }

    const int len = s.size();
    for (int i = 0; i < len / 2; i++) {
      if (s[i] != s[len - i - 1])
        return false;
    }

    return true;
  }
};

int main(int argc, char *argv[])
{
  Solution so;
  std::string test("aab");
  auto ret = so.isParlidrome(test);
  cout << ret << endl;
  auto tret = so.partition(test);
  for (auto &vec : tret) {
    for (auto s : vec) {
      cout << s << " ";
    }
    cout << endl;
  }

  return 0;
}
