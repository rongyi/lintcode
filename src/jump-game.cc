// http://www.lintcode.com/zh-cn/problem/jump-game

class Solution {
public:
  /**
   * @param A: A list of integers
   * @return: The boolean answer
   */
  bool canJump(vector<int> A) {
    int max_n = 0;
    for (int i = 0; i <= max_n; i++) {
      max_n = max(max_n, i + A[i]);
      if (max_n >= A.size() - 1)
        return true;
    }
    return false;
  }
};
