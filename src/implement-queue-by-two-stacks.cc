// http://www.lintcode.com/zh-cn/problem/implement-queue-by-two-stacks

#include <stack>
using namespace std;

class Queue {
public:
  stack<int> stack1;
  stack<int> stack2;

  Queue() {
    // do intialization if necessary
  }

  void push(int element) { stack1.push(element); }

  int pop() {
    if (!stack2.empty()) {
      int ret = stack2.top();
      stack2.pop();
      return ret;
    }
    while (!stack1.empty()) {
      int tmp = stack1.top();
      stack2.push(tmp);
      stack1.pop();
    }
    if (!stack2.empty()) {
      int ret = stack2.top();
      stack2.pop();
      return ret;
    }
    return -1;
  }

  int top() {
    if (!stack2.empty()) {
      return stack2.top();
    }
    while (!stack1.empty()) {
      int tmp = stack1.top();
      stack2.push(tmp);
      stack1.pop();
    }
    if (!stack2.empty()) {
      return stack2.top();
    }
    return -1;
  }
};
