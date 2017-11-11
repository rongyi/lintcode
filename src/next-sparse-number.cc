// http://www.lintcode.com/zh-cn/problem/next-sparse-number
#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /*
  * @param : a number
  * @return: return the next sparse number behind x
  * http://www.geeksforgeeks.org/given-a-number-find-next-sparse-number/
  */
  int nextSparseNum(int x) {
    vector<bool> bin;
    while (x) {
      bin.push_back(x & 0b1);
      x >>= 1;
    }
    bin.push_back(0);
    const int n = bin.size();
    int last_final = 0;
    for (int i = 1; i < n - 1; i++) {
      if (bin[i] == 1 && bin[i - 1] == 1 && bin[i + 1] != 1) {
        bin[i + 1] = 1;
        // 我的思路中没有把低位清掉，这里能保证是最小的，赞
        for (int j = i; j >= last_final; --j) {
          bin[j] = 0;
        }
        last_final = i + 1;
      }
    }
    int ret = 0;
    for (int i = 0; i < n; ++i) {
      ret += bin[i] * (1 << i);
    }
    return ret;
  }

  // this way is better:
  // http://www.geeksforgeeks.org/check-if-a-given-number-is-sparse-or-not/
  bool isSparseNum(int x) {
    while (x) {
      auto b = x & 0b1;
      auto n = x & 0b10;
      if (b == 0b1 && n == 0b10) {
        return false;
      }
      x >>= 1;
    }
    return true;
  }
};
int main() {
  Solution so;
  auto ret = so.nextSparseNum(44);
  cout << ret << endl;
  return 0;
}
