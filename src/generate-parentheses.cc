//http://www.lintcode.com/zh-cn/problem/generate-parentheses/
class Solution {
public:
  /**
   * @param n n pairs
   * @return All combinations of well-formed parentheses
   */
  vector<string> generateParenthesis(int n) {
    // Write your code here
    vector<string> ret;
    help(n, n, "", ret);
    return ret;
  }
private:
  void help(int left, int right, string s, vector<string> &ret) {
    if (left == 0 && right == 0)
      ret.push_back(s);
    if (left > 0)
      help(left - 1, right, s + '(', ret);
    if (right > 0 && left < right)
      help(left, right - 1, s + ')', ret);
  }
};
