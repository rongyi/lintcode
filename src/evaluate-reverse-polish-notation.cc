// http://www.lintcode.com/zh-cn/problem/evaluate-reverse-polish-notation/

class Solution {
public:
  /**
   * @param tokens The Reverse Polish Notation
   * @return the value
   */
  int evalRPN(vector<string> &tokens) {
    // Write your code here
    stack<string> s;

    for (auto token : tokens) {
      if (!is_operator(token)) {
        s.push(token);
      } else {
        int y = std::stoi(s.top());
        s.pop();
        int x = std::stoi(s.top());
        s.pop();
        if (token[0] == '+')
          x += y;
        else if (token[0] == '-')
          x -= y;
        else if (token[0] == '*')
          x *= y;
        else
          x /= y;
        s.push(std::to_string(x));
      }
    }
    return std::stoi(s.top());
  }

private:
  bool is_operator(const string &op) {
    static string valid_op("+-*/");
    return op.size() == 1 && valid_op.find(op) != string::npos;
  }
};
