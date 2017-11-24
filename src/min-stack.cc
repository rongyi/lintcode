// http://www.lintcode.com/zh-cn/problem/min-stack
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class MinStack {
public:
  MinStack() {
    // do initialization if necessary
  }

  void push(int number) {
    // push to normal as always
    normal_stack_.push(number);

    // note the equal compare
    // so the min stack keep a ascending order
    if (min_stack_.empty() || number <= min_stack_.top()) {
      min_stack_.push(number);
    }
  }

  int pop() {
    if (normal_stack_.empty())
      return -1;
    const int number = normal_stack_.top();
    // if the the min leave main, it should also leave min stack
    if (number <= min_stack_.top()) {
      min_stack_.pop();
    }
    normal_stack_.pop();

    return number;
  }

  int min() {
    if (min_stack_.empty())
      return -1;
    return min_stack_.top();
  }

private:
  std::stack<int> min_stack_;
  std::stack<int> normal_stack_;
};
