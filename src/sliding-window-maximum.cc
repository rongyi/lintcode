// http://www.lintcode.com/zh-cn/problem/sliding-window-maximum
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::deque;

class Solution {
public:
  /**
   * @param nums: A list of integers.
   * @return: The maximum number inside the window at each moving.
   */
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    vector<int> ret;
    deque<int> q;
    for (unsigned i = 0; i < nums.size(); i++) {
      if (!q.empty() && q.front() == i - k)
        q.pop_front();
      while (!q.empty() && nums[q.back()] < nums[i])
        q.pop_back();
      q.push_back(i);
      if (i >= k - 1)
        ret.push_back(nums[q.front()]);
    }

    return ret;
  }
};
int main() {
  Solution so;
  vector<int> test{1, 2, 7, 7, 8, 1, 2, 3};
  auto ret = so.maxSlidingWindow(test, 3);

  return 0;
}
