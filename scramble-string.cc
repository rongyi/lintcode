// http://www.lintcode.com/zh-cn/problem/scramble-string
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param s1 A string
   * @param s2 Another string
   * @return whether s2 is a scrambled string of s1
   */
  bool isScramble(string& s1, string& s2) {
    if (s1.size() != s2.size())
      return false;

    if (s1 == s2)
      return true;

    auto s1cp = s1;
    auto s2cp = s2;
    std::sort(s1cp.begin(), s1cp.end());
    std::sort(s2cp.begin(), s2cp.end());
    if (s1cp != s2cp)
      return false;

    for (int i = 1; i < s1.size(); i++) {
      auto s1sub1 = s1.substr(0, i);
      auto s2sub1 = s2.substr(0, i);
      auto s1sub2 = s1.substr(i);
      auto s2sub2 = s2.substr(i);

      if (isScramble(s1sub1, s2sub1) &&
          isScramble(s1sub2, s2sub2))
        return true;
      auto s2sub3 = s2.substr(s2.size() - i);
      auto s2sub4 = s2.substr(0, s2.size() - i);
      if (isScramble(s1sub1, s2sub3) &&
          isScramble(s1sub2, s2sub4))
        return true;
    }

    return false;
  }
};
int main()
{
  Solution so;
  string a("abcd");
  string b("bdac");
  auto ret = so.isScramble(a, b);
  cout << ret << endl;
  return 0;
}
