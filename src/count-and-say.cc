// http://www.lintcode.com/zh-cn/problem/count-and-say
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param n the nth
   * @return the nth sequence
   */
  string countAndSay(int n) {
    string ret = "1";
    for (int i = 1; i < n; i++) {
      const int len = ret.length();
      int start = 0;
      string tmp = "";
      for (int j = 1; j < len; j++) {
        if (ret[j] != ret[j - 1]) {
          tmp += std::to_string(j - start) + ret[j - 1];
          start = j;
        }
      }
      tmp += std::to_string(len - start) + ret[len - 1];
      ret = tmp;
    }
    return ret;
  }
};

int main()
{
  Solution so;
  auto ret = so.countAndSay(5);
  cout << ret << endl;
  return 0;
}
