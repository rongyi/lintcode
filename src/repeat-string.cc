// http://www.lintcode.com/zh-cn/problem/repeat-string
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /*
  * @param : string A to be repeated
  * @param : string B
  * @return: the minimum number of times A has to be repeated
  */
  int repeatedString(string &A, string &B) {
    if (A.empty()) {
      return -1;
    }
    const int n2 = B.size();
    int count = 1;
    string t = A;
    while (t.size() < n2) {
      t += A;
      ++count;
    }

    if (t.find(B) != string::npos) {
      return count;
    }
    t += A;
    return (t.find(B) != string::npos) ? count + 1 : -1;
  }
};
