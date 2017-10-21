// http://www.lintcode.com/zh-cn/problem/rotate-words
#include <unordered_set>
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
  * @param words: A list of words
  * @return: Return how many different rotate words
  */
  int countRotateWords(vector<string> words) {
    std::unordered_set<string> set;
    for (auto &s: words) {
      set.insert(s);
    }
    cout << set.size() << endl;

    for (auto &s : words) {
      if (set.find(s) == set.end()) {
        continue;
      }
      for (unsigned i = 1; i < s.length(); i++ ) {
        auto r = rotate(s, i);
        auto it = set.find(r);
        // special case equal to s, so we exclude it
        if (it != set.end() && *it != s) {
          set.erase(it);
        }
      }
    }

    return set.size();
  }

  string rotate(string s, int offset) {
    string str = s;
    for (int i = 0; i < offset; i++) {
      str.insert(str.begin(), str[str.length() - 1 - i]);
    }
    str.erase(str.end() - offset, str.end());

    return str;
  }
};

int main()
{
  Solution so;
  vector<string> input{"abba", "abab", "baba", "abab", "baba", "bbaa", "aabb"};
  auto ret = so.countRotateWords(input);
  cout << ret << endl;
  return 0;
}
