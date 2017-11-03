// http://www.lintcode.com/zh-cn/problem/first-missing-prime-number
#include <vector>
#include <iostream>
#include <string>
#include <cmath>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /*
  * @param : an array of integer
  * @return: the first missing prime number
  */
  int firstMissingPrime(vector<int> nums) {
    if (nums.size() == 0 || nums[0] != 2) {
      return 2;
    }

    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] - nums[i - 1] > 2) {
        int cur = nums[i - 1] + (nums[i - 1] % 2 == 0 ? 1 : 2);
        while (cur < nums[i]) {
          if (isPrime(cur)) {
            return cur;
          }
          cur += 2;
        }
      }
    }

    int start = nums[nums.size() - 1] + 2;
    while (true) {
      if (isPrime(start)) {
        return start;
      } else {
        start += 2;
      }
    }
  }

  bool isPrime(int n) {
    if (n == 2) {
      return true;
    }

    if (n % 2 == 0) {
      return false;
    }
    int upper = int(::sqrt(n));
    for (int i = 3; i <= upper; i = i + 2) {
      if (n % i == 0) {
        return false;
      }
    }

    return true;
  }
};
