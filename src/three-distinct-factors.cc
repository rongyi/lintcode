// http://www.lintcode.com/zh-cn/problem/three-distinct-factors
#include <cmath>
class Solution {
public:
  /*
  * @param : the given number
  * @return:  return true if it has exactly three distinct factors, otherwise
  * false
  */
  bool isThreeDisctFactorsTLE(long long n) {
    if (n < 4) {
      return false;
    }
    bool divided = false;
    for (long long i = 2; i < n - 1; ++i) {
      if (n % i == 0) {
        if (divided) {
          return false;
        }

        if (n / i != i) {
          return false;
        } else {
          divided = true;
        }
      }
    }
    return true;
  }
  bool isThreeDisctFactors(long long n) {
    int sq = (int)std::sqrt(n);
    if (1ll * sq * sq != n) {
      return false;
    }
    return isPrime(sq) ? true : false;
  }

  bool isPrime(long long n) {
    if (n <= 1) {
      return false;
    }
    if (n <= 3) {
      return true;
    }
    if (n % 2 == 0) {
      return false;
    }
    for (int i = 2; i * i < n; ++i) {
      if (n % i == 0) {
        return false;
      }
    }
    return true;
  }
};
