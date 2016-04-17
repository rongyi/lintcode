// http://www.lintcode.com/zh-cn/problem/climbing-stairs

class Solution {
public:
  /**
   * @param n: An integer
   * @return: An integer
   */
  int climbStairs(int n) {
    if (n <= 0)
      return 1;
    if (n == 1)
      return 1;
    if (n == 2)
      return 2;
    // return climbStairs(n - 1) + climbStairs(n - 2);
    int cur = 0;
    int p = 1;
    int q = 2;
    for (int i = 3; i <= n; i++) {
      cur = p + q;
      p = q;
      q = cur;
    }
    return cur;
  }
};
