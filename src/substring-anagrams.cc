// http://www.lintcode.com/zh-cn/problem/substring-anagrams
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
   * @param s a string
   * @param p a non-empty string
   * @return a list of index
   */
  vector<int> findAnagrams(string &s, string &p) {
    vector<int> ret;
    int sc[26] = {};
    int pc[26] = {};
    for (int i = 0; i < p.size(); ++i) {
      sc[s[i] - 'a']++;
      pc[p[i] - 'a']++;
    }
    if (cmp(sc, pc, 26))
      ret.push_back(0);

    // think p as a sliding window
    for (int i = p.size(); i < s.size(); i++) {
      // new entry for this window
      sc[s[i] - 'a']++;
      // drop after window tail
      sc[s[i - p.size()] - 'a']--;
      if (cmp(sc, pc, 26))
        ret.push_back(i - p.size() + 1);
    }


    return ret;
  }

private:
  bool cmp(const int a[], const int b[], int size) {
    for (int i = 0; i < size; ++i) {
      if (a[i] != b[i])
        return false;
    }
    return true;
  }
};


int main()
{
  Solution so;
  string s("abab");
  string p("ab");
  auto ret = so.findAnagrams(s, p);
  for (auto i : ret) {
    cout << i << endl;
  }

  return 0;
}
