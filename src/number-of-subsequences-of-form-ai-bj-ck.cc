// http://www.lintcode.com/zh-cn/problem/number-of-subsequences-of-form-ai-bj-ck
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
  /*
  * @param : the input string
  * @return: the number of subsequences
  */
  int countSubsequences(string &source) {
    int acount = 0;
    int bcount = 0;
    int ccount = 0;
    for (auto c : source) {
      if (c == 'a') {
        acount = (1 + 2 * acount);
      }
      if (c == 'b') {
        bcount = (acount + 2 * bcount);
      }
      if (c == 'c') {
        ccount = (bcount + 2 * ccount);
      }
    }
    return ccount;
  }
};
