// http://www.lintcode.com/zh-cn/problem/add-digits
#include <iostream>
class Solution {
public:
  /**
   * @param num a non-negative integer
   * @return one digit
   */
  int addDigits(int num) {
    if (num / 10 == 0)
      return num;

    auto ret = digitSum(num);
    while (ret >= 10) {
      ret = digitSum(ret);
    }

    return ret;
  }

private:
  int digitSum(int num) {
    auto ret = 0;
    while (num) {
      ret += (num % 10);
      num /= 10;
    }
    return ret;
  }
};

int main() {
  Solution so;
  auto test = so.addDigits(38);
  std::cout << test << std::endl;

  return 0;
}
