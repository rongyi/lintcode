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
    string seq = "1";

    for (int i = 1; i < n; i++) {
      int len = seq.length();
      int start = 0;
      string ret;
      for (int j = 1; j < len; j++) {
        if (seq[j] != seq[j - 1]) {
          ret += std::to_string(j - start) + seq[j - 1];
          start = j;
        }
      }
      ret += std::to_string(len - start) + seq[len - 1];
      seq = ret;
    }
    return seq;
  }
};

int main()
{
  Solution so;
  auto ret = so.countAndSay(5);
  cout << ret << endl;
  return 0;
}
