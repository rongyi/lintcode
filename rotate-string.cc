// http://www.lintcode.com/zh-cn/problem/rotate-string
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
   * @param str: a string
   * @param offset: an integer
   * @return: nothing
   */
  void rotateString(string &str,int offset){
    if (str.empty())
      return;
    const int n = str.length();
    offset = offset % n;
    for (int i = 0; i < offset; i++) {
      str.insert(str.begin(), str[str.length() - 1 - i]);
    }
    str.erase(str.end() - offset, str.end());
  }
};

int main()
{
  Solution so;
  std::string test("hellorongyi");
  so.rotateString(test, 2);
  cout << test << endl;;
  return 0;
}
