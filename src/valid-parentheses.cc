// http://www.lintcode.com/zh-cn/problem/valid-parentheses/

class Solution {
public:
  /**
   * @param s A string
   * @return whether the string is a valid parentheses
   */
  bool isValidParentheses(string& s) {
    // Write your code here
    const string left = "([{";
    const string right = ")]}";

    std::stack<char> stack;
    for (auto c : s) {
      if (left.find(c) != string::npos) {
        stack.push(c);
      } else {
        if (stack.empty() || stack.top() != left[right.find(c)]) {
          return false;
        } else {
          stack.pop();
        }
      }
    }
    return stack.empty();

  }
};
