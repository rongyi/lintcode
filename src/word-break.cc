// http://www.lintcode.com/zh-cn/problem/word-break
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
  /**
   * @param s: A string s
   * @param dict: A dictionary of words dict
   */
  bool wordBreak(string s, unordered_set<string> &dict) {
    const int n = s.length();
    // 有n+1个隔板
    vector<bool> ret_lst(s.length() + 1);
    ret_lst[0] = true;
    for (int i = 0; i < n; i++) {
      if (!ret_lst[i])
        continue;
      for (auto &cur_word : dict) {
        int l = cur_word.length();
        int j = i + l;
        if (j > n || ret_lst[j])
          continue;
        if (cur_word == s.substr(i, l))
          ret_lst[j] = true;
      }
    }
    return ret_lst[n];
  }
};

int main() {
  Solution so;
  unordered_set<string> test_set;
  test_set.insert("lint");
  test_set.insert("code");
  auto s = std::string("lintcode");
  auto ret = so.wordBreak(s, test_set);

  cout << ret << endl;
  return 0;
}
