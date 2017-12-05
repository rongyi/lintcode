// http://www.lintcode.com/zh-cn/problem/longest-substring-without-repeating-characters
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>

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

left标记的更新
q p x r j x k l t z y x
|--------|
      |--------------|
            |--------|
   */
  int lengthOfLongestSubstring(string s) {
    // 从左往右扫描，当遇到重复字母时，以上一个重复字母的index+1，作为新的搜索起始位置，
    // 直到最后一个字母。
    // left用以记录合法的最远左边界位置，last记录字符上一次出现的位置
    int ret = 0, left = 0, len = s.length();
    int last[255];
    std::memset(last, -1, sizeof last);

    for (int i = 0; i < len; i++) {
      // eject the duplicate char from left
      if (last[s[i]] >= left)
        left = last[s[i]] + 1;
      last[s[i]] = i;
      ret = std::max(ret, i - left + 1);
    }
    return ret;
  }
};

int main() {
  Solution so;
  auto ret = so.lengthOfLongestSubstring("abcabcdefg");
  cout << ret << endl;
  return 0;
}
