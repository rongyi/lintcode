// http://www.lintcode.com/zh-cn/problem/expression-evaluation
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::stack;

class Solution {
public:
  /**
   * @param expression: a vector of strings;
   * @return: an integer
   */
  int evaluateExpression(vector<string> &expression) {
    for (auto &enigma : expression) {
      switch (enigma[0]) {
      case '(':
        op_.push(enigma);
        break;
      case '+':
      case '-':
        while (!op_.empty() && op_.top()[0] != '(') {
          eval();
        }
        op_.push(enigma);
        break;
      case '*':
      case '/':
        while (!op_.empty() && (op_.top()[0] == '*' || op_.top()[0] == '/')) {
          eval();
        }
        op_.push(enigma);
        break;
      case ')':
        while (op_.top()[0] != '(') {
          eval();
        }
        op_.pop();
        break;
      default:
        number_.push(std::stoi(enigma));
        break;
      }
    } // for end

    while (!op_.empty()) {
      eval();
    }
    if (number_.empty())
      return 0;

    return number_.top();
  }

private:
  void eval() {
    auto op = op_.top();
    op_.pop();

    auto number1 = number_.top();
    number_.pop();

    auto number2 = number_.top();
    number_.pop();

    int eval_ret = 0;
    switch (op[0]) {
    case '+':
      eval_ret = number2 + number1;
      break;
    case '-':
      eval_ret = number2 - number1;
      break;
    case '*':
      eval_ret = number2 * number1;
      break;
    case '/':
      eval_ret = number2 / number1;
      break;
    }
    number_.push(eval_ret);
  }

private:
  stack<string> op_;
  stack<int> number_;
};

int main() {
  Solution so;
  vector<string> input{"2", "-", "6", "*", "(", "23", "+", "7",
                       ")", "/", "(", "1", "+", "2",  ")"};
  auto ret = so.evaluateExpression(input);
  cout << ret << endl;

  return 0;
}
