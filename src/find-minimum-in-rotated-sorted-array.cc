// http://www.lintcode.com/zh-cn/problem/find-minimum-in-rotated-sorted-array
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
   * @param num: a rotated sorted array
   * @return: the minimum number in the array
   */
  int findMin(vector<int> &nums) {
    if (nums.empty())
      return -1;
    // const int n = nums.size();
    int start = 0;
    int end = nums.size() - 1;

    while (start <= end) {
      const int mid = start + (end - start) / 2;
      // in regular
      if (nums[start] <= nums[end]) {
        break;
      } else {
        // not in a rotated list
        if (nums[start] <= nums[mid] && nums[mid] >= nums[end]) {
          start = mid + 1;
        } else if (nums[start] >= nums[mid] && nums[start] >= nums[end]) {
          start += 1;
        } else {
          end = mid - 1;
        }
      }
    }

    return nums[start];
  }
};

int main() {
  Solution so;
  vector<int> test{1, 2, 3};
  auto ret = so.findMin(test);
  cout << ret << endl;
  return 0;
}
