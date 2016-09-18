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

    // 题意为求不包含重复字符的最长子串
    // left用以记录合法的最远左边界位置，last记录字符上一次出现的位置
    int ans = 0, left = 0, len = s.length();
    int last[255];
    std::memset(last, -1, sizeof last);

    for (int i = 0; i < len; i++) {
      // 上次出现位置在当前记录边界之后，即该子串中出现了重复字符，需调整left使得子串合法
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
