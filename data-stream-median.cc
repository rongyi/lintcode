// http://www.lintcode.com/zh-cn/problem/data-stream-median
#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::priority_queue;

class Solution {
public:
  /**
   * @param nums: A list of integers.
   * @return: The median of numbers
   */
  vector<int> medianII(vector<int> &nums) {
    vector<int> ret;
    if (nums.empty())
      return ret;

    // array layout
    // --------------max_heap-----------|----------------min_heap--------------
    priority_queue<int, vector<int>, std::greater<int>> min_heap;
    priority_queue<int, vector<int>, std::less<int>> max_heap;

    for (auto i : nums) {
      if (max_heap.empty() || i > max_heap.top()) {
        min_heap.emplace(i);
        if (min_heap.size() > max_heap.size() + 1) {
          max_heap.emplace(min_heap.top());
          min_heap.pop();
        }
      } else {
        max_heap.emplace(i);
        if (max_heap.size() > min_heap.size()) {
          min_heap.emplace(max_heap.top());
          max_heap.pop();
        }
      }

      ret.emplace_back(min_heap.size() == max_heap.size() ?
                       max_heap.top() : min_heap.top());
    }

    return ret;
  }
};

int main()
{
  Solution so;
  vector<int> test{1, 3, 2, 9, 7};
  so.medianII(test);
  return 0;
}
