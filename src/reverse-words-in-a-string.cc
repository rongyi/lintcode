// http://www.lintcode.com/zh-cn/problem/reverse-words-in-a-string
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::stack;
using std::stringstream;

class Solution {
public:
  /**
   * @param s : A string
   * @return : A string
   */
  string reverseWords(string s) {
    // string trim
    s.erase(0, s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
    if (s.empty())
      return "";
    stringstream ss;
    stack<char> help_stack;
    stack<char> help_stack2;
    for (auto c : s) {
      if (c == ' ') {
        while (!help_stack.empty()) {
          help_stack2.push(help_stack.top());
          help_stack.pop();
        }
        help_stack2.push(' ');
      } else {
        help_stack.push(c);
      }
    }
    // clear stack1
    while (!help_stack.empty()) {
      help_stack2.push(help_stack.top());
      help_stack.pop();
    }

    while (!help_stack2.empty()) {
      ss << help_stack2.top();
      help_stack2.pop();
    }

    return ss.str();
  }
};

int main(int argc, char *argv[]) {
  string test("the sky is blue");
  Solution so;
  auto ret = so.reverseWords(test);
  cout << ret << endl;
  return 0;
}
