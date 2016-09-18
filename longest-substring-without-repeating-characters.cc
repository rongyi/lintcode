// http://www.lintcode.com/zh-cn/problem/longest-substring-without-repeating-characters
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <cstring>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::map;

class Solution {
public:
  /**
   * @param s: a string
   * @return: an integer
   */
  int lengthOfLongestSubstring(string s) {
    // left用以记录合法的最远左边界位置，last记录字符上一次出现的位置
    int ans = 0, left = 0, len = s.length();
    int last[255];
    std::memset(last, -1, sizeof last);

    for (int i = 0; i < len; i++) {
      // eject the duplicate char from left
      if (last[s[i]] >= left)
        left = last[s[i]] + 1;
      last[s[i]] = i;
      ans = std::max(ans, i - left + 1);
    }
    return ans;
  }
};

int main()
{
  Solution so;
  auto ret = so.lengthOfLongestSubstring("abcabcdefg");
  cout << ret << endl;
  return 0;
}
