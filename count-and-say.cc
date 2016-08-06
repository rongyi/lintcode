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
      std::stringstream ss;
      char last = seq[0];
      int count = 0;
      for (int j = 0; j <= seq.size(); j++) {
        if (seq[j] == last) {
          count++;
          continue;
        } else {
          ss << count << last;
          last = seq[j];
          count = 1;
        }
      }
      seq = ss.str();
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
