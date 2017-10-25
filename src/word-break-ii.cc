// http://www.lintcode.com/zh-cn/problem/word-break-ii
#include <iostream>
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
  vector<string> wordBreak(string s, unordered_set<string> &dict) {
    // 长度为n的字符串有n+1个隔板
    vector<bool> f(s.length() + 1, false);
    // prev[i][j]为true，表示s[j, i)是一个合法单词，可以从j处切开
    // 第一行未用
    vector<vector<bool>> prev(s.length() + 1, vector<bool>(s.length()));
    f[0] = true;
    for (size_t i = 1; i <= s.length(); ++i) {
      for (int j = i - 1; j >= 0; --j) {
        string tmp = s.substr(j, i - j);
        // 如果j出可以隔开，而且s[j, i)也在字典里，那么i处也可以隔开
        // 并且缓存索引用于后面直接查找
        if (f[j] && dict.find(tmp) != dict.end()) {
          f[i] = true;
          prev[i][j] = true;
        }
      }
    }
    vector<string> ret;
    vector<string> path;
    // 从最后边开始查找，传s.length()大小表示从末尾开始切割，即第一刀是完整的原始字符
    gen_path(s, prev, s.length(), path, ret);
    return ret;
  }

private:
  // DFS遍历树，生成路径
  void gen_path(const string &s, const vector<vector<bool>> &prev, int cur,
                vector<string> &path, vector<string> &ret) {
    // 找到头了，这时候将path添加到ret
    if (cur == 0) {
      string tmp;
      for (auto iter = path.crbegin(); iter != path.crend(); ++iter)
        tmp += *iter + " ";
      tmp.erase(tmp.end() - 1);
      ret.push_back(tmp);
    }
    for (size_t i = 0; i < s.size(); ++i) {
      // 表示i位置可以切下去，即保证下面tmp这个字符串在字典里
      if (prev[cur][i]) {
        string tmp = s.substr(i, cur - i);
        path.push_back(tmp);
        // 再从i这个位置开始往前找下一个位置可以切下去
        gen_path(s, prev, i, path, ret);
        path.pop_back();
      }
    }
  }
};

int main() {
  Solution so;
  string test{"lintcode"};
  std::unordered_set<string> dict{"lint", "code", "co", "de"};
  auto ret = so.wordBreak(test, dict);
  for (auto &s : ret)
    cout << s << endl;
  return 0;
}
