// http://www.lintcode.com/zh-cn/problem/add-operators
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
   * @param num a string contains only digits 0-9
   * @param target an integer
   * @return return all possibilities
   */
  vector<string> addOperators(string &num, int target) {
    vector<string> ret;

    dfs(num, target, 0, 0, "", ret);
    return ret;
  }

private:
  void dfs(string num, int target, long long diff, long long cur_num, string out, vector<string> &ret) {
    if (num.size() == 0 && cur_num == target) {
      ret.push_back(out);
    }
    for (int i = 1; i <= num.size(); ++i) {
      string cur = num.substr(0, i);
      if (cur.size() > 1 && cur[0] == '0')
        return;
      string next = num.substr(i);
      long long tmp = std::stoll(cur);
      if (out.size() > 0) {
        dfs(next, target, tmp, cur_num + tmp, out + "+" + cur, ret);
        dfs(next, target, -tmp, cur_num - tmp, out + "-" + cur, ret);
        dfs(next, target, diff * tmp, (cur_num - diff) + diff * tmp, out + "*" + cur, ret);
      } else {
        dfs(next, target, std::stoll(cur), std::stoll(cur), cur, ret);
      }
    }
  }
};

int main()
{
  Solution so;
  string num{"123"};
  int t = 6;
  auto ret = so.addOperators(num, t);
  for (auto &s : ret) {
    cout << s << endl;
  }
  return 0;
}
