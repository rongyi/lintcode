// http://www.lintcode.com/zh-cn/problem/happy-number/

class Solution {
public:
  /**
   * @param n an integer
   * @return true if this is a happy number or false
   */
  bool isHappy(int n) {
    if (n == 1) {
      return true;
    }
    bool is_occur = false;
    for (int i = 0; ; i++) {
      int next = next_happy(n);
      if (next == 1)
        return true;
      // 所有不快乐数的数位平方和计算，最后都会进入 4 → 16 → 37 → 58 → 89 → 145 → 42 → 20 → 4 的循环中
      if (next == 4) {
        if (is_occur)
          return false;
        else
          is_occur = true;
      }
      n = next;
    }
  }
private:
  int next_happy(int n) {
    int sum = 0;
    while (n) {
      int digit = n % 10;
      sum += digit * digit;
      n /= 10;
    }
    return sum;
  }
};
