// http://www.lintcode.com/zh-cn/problem/trailing-zeros
#include <algorithm>
#include <iostream>

class Solution {
public:
  // param n : description of n
  // return: description of return
  long long trailingZeros(long long n) {
    long long ret = 0;
    for (int i = 1; std::pow(5, i) <= n; i++) {
      ret += n / (long)std::pow(5, i);
    }
    return ret;
  }
};

int main(int argc, char *argv[])
{
  Solution so;
  auto ret = so.trailingZeros(11);
  std::cout << ret << std::endl;
  return 0;
}
