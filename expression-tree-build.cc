// http://www.lintcode.com/zh-cn/problem/expression-tree-build
#include <vector>
#include <iostream>
#include <string>
#include <stack>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::stack;

/**
 * Definition of ExpressionTreeNode:
 * class ExpressionTreeNode {
 * public:
 *     string symbol;
 *     ExpressionTreeNode *left, *right;
 *     ExpressionTreeNode(string symbol) {
 *         this->symbol = symbol;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class ExpressionTreeNode {
public:
  string symbol;
  ExpressionTreeNode *left, *right;
  ExpressionTreeNode(string symbol) {
    this->symbol = symbol;
    this->left = this->right = nullptr;
  }
};

class Solution {
public:
  /**
   * @param expression: A string array
   * @return: The root of expression tree
   for any calculator problems, keep 2 stacks: 1 for operators and 1 for operands
   */
  ExpressionTreeNode* build(vector<string> &expression) {
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
        while (!op_.empty() && (op_.top()->symbol[0] == '*' || op_.top()->symbol[0] == '/')) {
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
int main()
{
  Solution so;
  vector<string> input{"2","*","6","-","(","23","+","7",")","/","(","1","+","2",")"};
  auto ret = so.build(input);
  return 0;
}
