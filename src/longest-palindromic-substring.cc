// http://www.lintcode.com/zh-cn/problem/longest-palindromic-substring
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::stack;

class Solution {
public:
  /**
   * @param s input string
   * @return the longest palindromic substring
   */
  string longestPalindrome2(string &s) {
    string result;
    if (s.empty())
      return s;

    int n = s.size();
    int longest = 0, left = 0, right = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j <= n; ++j) {
        string substr = s.substr(i, j - i);
        if (isPalindrome(substr) && substr.size() > longest) {
          longest = j - i;
          left = i;
          right = j;
        }
      }
    }

    result = s.substr(left, right - left);
    return result;
  }

  string longestPalindrome(string &s) {
    const int n = s.size();
    bool f[n][n];
    std::fill_n(&f[0][0], n * n, 0);

    unsigned max_len = 1;
    unsigned start = 0;
    for (unsigned i = 0; i < s.size(); ++i) {
      f[i][i] = true;
      for (unsigned j = 0; j < i; ++j) {
        // 从j到i为回文的条件是首尾字符相等（要么相邻要么去掉这两个首尾字符也是回文）
        f[j][i] = (s[j] == s[i] && (i - j < 2 || f[j + 1][i - 1]));
        if (f[j][i] && max_len < (i - j + 1)) {
          max_len = i - j + 1;
          start = j;
        }
      }
    }

    return s.substr(start, max_len);
  }

private:
  bool isPalindrome(string &s) {
    int n = s.size();
    for (int i = 0; i < n; ++i) {
      if (s[i] != s[n - i - 1])
        return false;
    }
    return true;
  }
};
