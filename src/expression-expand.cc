// http://www.lintcode.com/zh-cn/problem/expression-expand
#include <vector>
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <sstream>
#include <cctype>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::stack;

class Solution {
public:
  /**
   * @param s  an expression includes numbers, letters and brackets
   * @return a string
   */
  string expressionExpand(string& s) {
    std::stringstream ss;
    stack<char> aux;

    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ']') {
        string exp;
        while (!aux.empty() && aux.top() != '[') {
          exp.insert(exp.begin(), aux.top());
          aux.pop();
        }
        // ignore '['
        aux.pop();
        int repeat = 0;
        int level = 1;
        while (!aux.empty() && std::isdigit(aux.top())) {
          repeat += (aux.top() - '0') * level;
          level *= 10;
          aux.pop();
        }

        for (int k = 0; k < repeat; k++) {
          for (auto c : exp) {
            aux.push(c);
          }
        }
      } else {
        aux.push(s[i]);
      }
    }

    while (!aux.empty()) {
      ss << aux.top();
      aux.pop();
    }
    string ret = ss.str();
    std::reverse(ret.begin(), ret.end());

    return ret;
  }
};

int main()
{
  Solution so;
  string test("10[a]dy");
  auto ret = so.expressionExpand(test);
  cout << ret << endl;
  return 0;
}
