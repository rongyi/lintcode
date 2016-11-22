// http://www.lintcode.com/zh-cn/problem/two-strings-are-anagrams
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
   * @param s: The first string
   * @param b: The second string
   * @return true or false
   */
  bool anagram(string s, string t) {
    if (s.empty() && t.empty())
      return true;
    std::string cs = s;
    std::string ct = t;
    std::sort(cs.begin(), cs.end());
    std::sort(ct.begin(), ct.end());
    return cs == ct;
  }
};

int main()
{
  Solution so;
  cout << so.anagram("abcd", "dbca") << endl;
  return 0;
}
