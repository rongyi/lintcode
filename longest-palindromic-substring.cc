// http://www.lintcode.com/zh-cn/problem/longest-palindromic-substring
#include <vector>
#include <iostream>
#include <string>
#include <stack>

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
  string longestPalindrome(string& s) {
    string result;
    if (s.empty()) return s;

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

private:
  bool isPalindrome(string &s) {
    int n = s.size();
    for (int i = 0; i < n; ++i) {
      if (s[i] != s[n - i - 1]) return false;
    }
    return true;
  }
};
