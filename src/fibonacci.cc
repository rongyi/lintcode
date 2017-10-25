// http://www.lintcode.com/zh-cn/problem/fibonacci/

class Solution {
public:
  /**
   * @param n: an integer
   * @return an integer f(n)
   */
  int fibonacci(int n) {
    int a = 0;
    int b = 1;
    for (int i = 1; i < n; i++) {
      b = a + b;
      a = b - a;
    }

    return a;
  }
};
