// http://www.lintcode.com/zh-cn/problem/largest-rectangle-in-histogram
#include <vector>
#include <iostream>
#include <string>
#include <stack>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::stack;


class Solution {
public:
  /**
   * @param height: A list of integer
   * @return: The area of largest rectangle in the histogram
   */
  int largestRectangleArea(vector<int> &height) {
    // write your code here
    stack<int> s;
    // 就是要让最后一个元素也要开始统计
    height.push_back(0);

    int ret = 0;
    for (int i = 0; i < height.size();) {
      if (s.empty() || height[i] > height[s.top()]) {
        s.push(i++);
      } else {
        // 走到这个逻辑的i是一直不变的，所以会一直把栈清空算完，可以
        // 如果不清楚可以通过例子[1, 2, 3, 4, 5]进行类比
        int tmp = s.top();
        s.pop();
        auto w = s.empty() ? i : i - s.top() - 1;
        ret = std::max(ret, height[tmp] * w);
      }
    }

    return ret;

  }
};

int main()
{
  Solution so;
  vector<int> test{1, 2, 3, 4, 5};
  auto ret = so.largestRectangleArea(test);
  cout << ret << endl;
  return 0;
}
