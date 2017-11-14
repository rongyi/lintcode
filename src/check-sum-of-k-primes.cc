// http://www.lintcode.com/zh-cn/problem/check-sum-of-k-primes
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
  * @param : an int
  * @param : an int
  * @return: if N can be expressed in the form of sum of K primes, return true;
  * otherwise, return false.
  * http://www.geeksforgeeks.org/check-number-can-written-sum-k-prime-numbers/
  */
  bool isSumOfKPrimes(int n, int k) {
    if (n < 2 * k) {
      return false;
    }
    if (k == 1) {
      return isPrime(n);
    }
    if (k == 2) {
      if (n % 2 == 0) {
        return true;
      }
      return isPrime(n - 2);
    }

    return true;
  }
private:
  bool isPrime(int n) {
    for (int i = 2; i * i <= n; i++) {
      if (n % i == 0) {
        return false;
      }
    }
    return true;
  }
};
