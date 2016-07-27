// http://www.lintcode.com/zh-cn/problem/palindrome-partitioning
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
   * @param s: A string
   * @return: A list of lists of string
   */
  vector<vector<string>> partition(string s) {
    vector<vector<string>> ret;
    return ret;
  }

public:
  bool isParlidrome(const string s) {
    if (s.empty() || s.size() == 1) {
      return true;
    }

    const int len = s.size();
    for (int i = 0; i < len / 2 - 1; i++) {
      if (s[i] != s[len - i - 1])
        return false;
    }

    return true;
  }
};

int main(int argc, char *argv[])
{
  Solution so;
  std::string test("abbac");
  auto ret = so.isParlidrome(test);
  cout << ret << endl;
  return 0;
}
