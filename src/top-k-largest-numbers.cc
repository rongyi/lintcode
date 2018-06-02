// http://www.lintcode.com/zh-cn/problem/top-k-largest-numbers
#include <vector>
#include <iostream>
#include <string>
#include <queue>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param nums: an integer array
   * @param k: An integer
   * @return: the top k largest numbers in array
   */
  vector<int> topk(vector<int> &nums, int k) {
    std::priority_queue<int, vector<int>, std::less<int>> max_heap;
    for (auto n : nums) {
      max_heap.push(n);
    }
    vector<int> ret;
    while (k--) {
      ret.push_back(max_heap.top());
      max_heap.pop();
    }
    return ret;
  }
};

int main() {
  Solution so;
  vector<int> test{3,10,1000,-99,4,100};
  auto ret = so.topk(test, 3);
  for (auto i: ret)
    cout << i << endl;
}
