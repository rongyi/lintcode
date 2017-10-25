// http://www.lintcode.com/zh-cn/problem/delete-digits
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   *@param A: A positive integer which has N digits, A is a string.
   *@param k: Remove k digits.
   *@return: A string

   想让一个数字尽可能小，那么就要把小的数字尽量放到前面，如果前面有比它大的数字，
   那么就到把在它前面且比它大的数字都要删除掉，直到已经删掉k个数字
   */
  string DeleteDigits(string a, int k) {
    std::string ret;

    for (auto const c : a) {
      while (!ret.empty() && k > 0 && ret.back() > c) {
        ret.pop_back();
        --k;
      }
      ret.push_back(c);
    }
    ret.resize(ret.length() - k);

    return ret.empty() ? "0" : ret.substr(ret.find_first_not_of('0'));
  }
};

int main() {
  Solution so;
  auto ret = so.DeleteDigits("178542", 4);
  cout << ret << endl;
  return 0;
}
