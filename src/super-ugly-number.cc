// http://www.lintcode.com/zh-cn/problem/super-ugly-number
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
   * @param n a positive integer
   * @param primes the given prime list
   * @return the nth super ugly number
   */
  int nthSuperUglyNumber(int n, vector<int> &primes) {
    vector<int> ret(1, 1);
    // 之前题目2， 3， 5扩展为n个的情况, 请参考之前的例子
    vector<int> index(primes.size(), 0);

    while (ret.size() < n) {
      vector<int> tmp;
      int cur = std::numeric_limits<int>::max();
      for (int i = 0; i < primes.size(); i++) {
        tmp.push_back(ret[index[i]] * primes[i]);
      }
      for (int i = 0; i < primes.size(); i++) {
        cur = std::min(cur, tmp[i]);
      }
      for (int i = 0; i < primes.size(); ++i) {
        if (cur == tmp[i])
          ++index[i];
      }
      ret.push_back(cur);
    }
    return ret.back();
  }
};
