// http://www.lintcode.com/zh-cn/problem/largest-rectangle-in-histogram

class Solution {
public:
  /**
   * @param height: A list of integer
   * @return: The area of largest rectangle in the histogram
   */
  int largestRectangleArea(vector<int> &height) {
    // write your code here
    stack<int> s;
    height.push_back(0);

    int ret = 0;
    for (int i = 0; i < height.size();) {
      if (s.empty() || height[i] > height[s.top()]) {
        s.push(i++);
      } else {
        int tmp = s.top();
        s.pop();
        ret = std::max(ret, height[tmp] * (s.empty() ? i : i - s.top() - 1));
      }
    }

    return ret;

  }
};
