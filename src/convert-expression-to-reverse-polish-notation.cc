// http://www.lintcode.com/zh-cn/problem/convert-expression-to-reverse-polish-notation
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::stack;

namespace detail {

struct ExpressionTreeNode {
  string symbol;
  ExpressionTreeNode *left, *right;
  ExpressionTreeNode(string symbol) {
    this->symbol = symbol;
    this->left = this->right = nullptr;
  }
};

class Expression {
public:
  // caller be aware!!
  // call build/free in pair
  ExpressionTreeNode *build(vector<string> &expression) {
    for (auto &enigma : expression) {
      ExpressionTreeNode *node = new ExpressionTreeNode(enigma);

      switch (enigma[0]) {
      case '(':
        op_.push(node);
        break;
      case '+':
      case '-':
        while (!op_.empty() && op_.top()->symbol[0] != '(') {
          eval();
        }
        op_.push(node);
        break;
      case '*':
      case '/':
        while (!op_.empty() &&
               (op_.top()->symbol[0] == '*' || op_.top()->symbol[0] == '/')) {
          eval();
        }
        op_.push(node);
        break;
      case ')':
        while (op_.top()->symbol[0] != '(') {
          eval();
        }
        op_.pop();
        break;
      default:
        number_.push(node);
        break;
      }
    } // for end

    while (!op_.empty()) {
      eval();
    }
    if (number_.empty())
      return nullptr;

    return number_.top();
  }

  void free() {
    if (number_.empty())
      return;
    ExpressionTreeNode *root = number_.top();
    number_.pop();

    doFree(root);
  }

  void doFree(ExpressionTreeNode *root) {
    if (!root)
      return;
    if (root->left)
      doFree(root->left);
    if (root->right)
      doFree(root->right);
    delete root;
  }

  void traversal(ExpressionTreeNode *root, vector<string> &acc) {
    if (!root)
      return;
    if (root->left)
      traversal(root->left, acc);
    if (root->right)
      traversal(root->right, acc);

    acc.push_back(root->symbol);
  }

private:
  void eval() {
    auto opnode = op_.top();
    op_.pop();

    auto number1 = number_.top();
    number_.pop();

    auto number2 = number_.top();
    number_.pop();

    opnode->left = number2;
    opnode->right = number1;

    number_.push(opnode);
  }

private:
  stack<ExpressionTreeNode *> op_;
  stack<ExpressionTreeNode *> number_;
};
} // namespace detail

class Solution {
public:
  /**
   * @param expression: A string array
   * @return: The Reverse Polish notation of this expression
   */
  vector<string> convertToRPN(vector<string> &expression) {
    detail::ExpressionTreeNode *root = expression_.build(expression);
    vector<string> ret;

    expression_.traversal(root, ret);
    expression_.free();

    return ret;
  }

  detail::Expression expression_;
};

int main() {
  Solution so;

  vector<string> input{"2", "-", "6", "*", "(", "23", "+", "7",
                       ")", "/", "(", "1", "+", "2",  ")"};
  auto ret = so.convertToRPN(input);
  for (auto s : ret)
    cout << s << endl;
  return 0;
}
