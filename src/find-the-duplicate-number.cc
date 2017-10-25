// http://www.lintcode.com/zh-cn/problem/find-the-duplicate-number
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param nums an array containing n + 1 integers which is between 1 and n
   * @return the duplicate one
   */
  int findDuplicate(vector<int> &nums) {
    int low = 1;
    int high = nums.size() - 1;
    while (low < high) {
      int mid = low + (high - low) * 0.5;
      int count = 0;
      for (auto a : nums) {
        if (a <= mid) {
          ++count;
        }
      } // end for
      // the lower part has no duplicate
      if (count <= mid) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return low;
  }
};

int main() {
  Solution so;
  vector<int> test{5, 5, 4, 3, 2, 1};
  auto ret = so.findDuplicate(test);
  cout << ret << endl;
  return 0;
}
