//http://www.lintcode.com/zh-cn/problem/generate-parentheses/
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param n n pairs
   * @return All combinations of well-formed parentheses
   */
  vector<string> generateParenthesis1(int n) {
    // Write your code here
    vector<string> ret;
    help(n, n, "", ret);
    return ret;
  }

  // 采用深搜来实现
  vector<string> generateParenthesis(int n) {
    vector<string> ret;
    vector<string> path;
    if (n > 0) {
      generate(n ,path, ret, 0, 0);
    }
    return ret;
  }
private:
  void generate(int n, vector<string> &path, vector<string> &ret, int l, int r) {
    if (l == n) {
      // 这里copy出来，为的是和下面的pop_back对应
      auto cp = path;
      for (int i = 0; i < n - r; ++i) {
        cp.push_back(")");
      }
      string tmp = reduce(cp);
      ret.push_back(tmp);
      return;
    }
    path.push_back("(");
    generate(n, path, ret, l + 1, r);
    path.pop_back();

    if (l > r) {
      path.push_back(")");
      generate(n, path, ret, l, r + 1);
      path.pop_back();
    }
  }

  void help(int left, int right, string s, vector<string> &ret) {
    if (left == 0 && right == 0)
      ret.push_back(s);
    if (left > 0)
      help(left - 1, right, s + '(', ret);
    if (right > 0 && left < right)
      help(left, right - 1, s + ')', ret);
  }

  string reduce(vector<string> &ps) {
    std::stringstream ss;
    for (auto &s : ps) {
      ss << s;
    }
    return ss.str();
  }
};

int main()
{
  Solution so;
  auto ret = so.generateParenthesis(3);
  for (auto &s : ret)
    cout << s << endl;
  return 0;
}
