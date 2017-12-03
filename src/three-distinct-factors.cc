// http://www.lintcode.com/zh-cn/problem/three-distinct-factors
// #include <climits>
// #include <cctype>
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
};
