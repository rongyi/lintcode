// http://www.lintcode.com/zh-cn/problem/132-pattern

#include <iostream>
#include <limits>
#include <stack>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::stack;

class Solution {
public:
  /**
   * @param nums a list of n integers
   * @return true if there is a 132 pattern or false
   */
  bool find132pattern(vector<int> &nums) {
    // the current minimum number
    int min = std::numeric_limits<int>::min();
    stack<int> s;
    for (int i = nums.size() - 1; i >= 0; --i) {
      // we find the order
      if (nums[i] < min) {
        return true;
      } else {
        while (!s.empty() && nums[i] > s.top()) {
          min = s.top();
          s.pop();
        }
      }
      s.push(nums[i]);
    }

    return false;
  }
};

int main() {
  Solution so;
  vector<int> test{1, 10, 4, 9, 2};
  auto ret = so.find132pattern(test);
  cout << ret << endl;
  return 0;
}
