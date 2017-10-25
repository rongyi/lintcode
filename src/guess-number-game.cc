// http://www.lintcode.com/zh-cn/problem/guess-number-game
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return
// 0
int guess(int num);

int guess(int num) {
  if (num == 2147483647) {
    return 0;
  } else if (num > 2147483647) {
    return -1;
  } else {
    return 1;
  }
}

class Solution {
public:
  /**
   * @param n an integer
   * @return the number you guess
   */
  int guessNumber(int n) {
    int64_t left = 1;
    int64_t right = n;
    while (left <= right) {
      int64_t mid = left + (right - left) * 0.5;
      int cmp = guess(int64_t(mid));
      if (cmp == 0) {
        return mid;
      } else if (cmp < 0) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    return -1;
  }
};

int main() {
  Solution so;
  so.guessNumber(2147483647);

  return 0;
}
