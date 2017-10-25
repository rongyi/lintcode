// http://www.lintcode.com/zh-cn/problem/single-number

class Solution {
public:
  /**
   * @param A: Array of integers.
   * return: The single number.
   */
  int singleNumber(vector<int> &A) {
    int ret = 0;
    for (vector<int>::const_iterator iter = A.begin(); iter != A.end();
         iter++) {
      ret ^= (*iter);
    }
    return ret;
  }
};
