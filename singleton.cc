// http://www.lintcode.com/zh-cn/problem/singleton/
class Solution {
public:
  /**
   * @return: The same instance of this class every time
   */
  static Solution* getInstance() {
    static Solution *ins = NULL;
    if (!ins)
      ins = new Solution();
    return ins;
  }
};
