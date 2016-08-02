// http://www.lintcode.com/zh-cn/problem/kth-largest-element
#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /*
   * param k : description of k
   * param nums : description of array and index 0 ~ n-1
   * return: description of return
   */
  int kthLargestElement(int k, vector<int> nums) {
    std::priority_queue<int, vector<int>, std::less<int>> pq;
    for (auto i : nums) {
      pq.push(i);
    }
    k--;
    if (k < 0)
      return -1;
    while (k) {
      pq.pop();
      k--;
    }

    return pq.top();
  }
};

int main()
{
  Solution so;
  vector<int> test{9, 3, 2, 4, 8};
  auto ret = so.kthLargestElement(3, test);
  cout << ret << endl;
  return 0;
}
