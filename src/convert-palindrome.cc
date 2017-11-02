// http://www.lintcode.com/zh-cn/problem/convert-palindrome
#include <algorithm>
#include <bitset>
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  // http://www.geeksforgeeks.org/minimum-characters-added-front-make-string-palindrome/
  string convertPalindrome(string str) {
    string rev = str;
    std::reverse(rev.begin(), rev.end());
    string concat = str + "$" + rev;
    auto lps = lpsArray(concat);

    int min_char = str.length() - lps.back();
    string con_section = rev.substr(0, min_char);

    return con_section + str;
  }


  vector<int> lpsArray(const string &str) {
    const int n = str.length();
    vector<int> ret(n);
    int len = 0;
    ret[0] = 0;

    for (int i = 1; i < n;) {
      if (str[i] == str[len]) {
        len++;
        ret[i] = len;
        i++;
      } else {
        if (len != 0) {
          len = ret[len - 1];
        } else {
          ret[i] = 0;
          i++;
        }
      }
    }

    return ret;
  }

  string convertPalindromeStillTLE(string str) {
    string rev = str;
    std::reverse(rev.begin(), rev.end());
    auto count = 0;
    while (rev != str) {
      count++;
      str.insert(count - 1, 1, rev[count - 1]);
      rev = str;
      std::reverse(rev.begin(), rev.end());
    }
    return rev;
  }


  /*
  * @param : String
  * @return: String
  */
  string convertPalindromeTLE(string str) {
    if (isPalindrome(str)) {
      return str;
    }
    string fixs = str.substr(1);
    std::reverse(fixs.begin(), fixs.end());
    for (int i = 0; i < fixs.size() - 1; i++) {
      string fix = fixs.substr(0, i + 1);
      string concat = fix + str;
      if (isPalindrome(concat)) {
        return concat;
      }
    }
    // last one
    return fixs + str;
  }

private:
  bool isPalindrome(string &s) {
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    auto left = s.begin();
    auto right = std::prev(s.end());
    while (left < right) {
      if (!::isalnum(*left))
        ++left;
      else if (!::isalnum(*right))
        --right;
      else if (*left != *right)
        return false;
      else {
        left++;
        right--;
      }
    }
    return true;
  }
};

int main()
{
  Solution so;
  string t{"aacecaaa"};
  auto ret = so.convertPalindrome(t);
  cout << ret << endl;
  return 0;
}
