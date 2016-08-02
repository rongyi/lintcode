// http://www.lintcode.com/zh-cn/problem/find-minimum-in-rotated-sorted-array-ii
#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param num: the rotated sorted array
   * @return: the minimum number in the array
   */
  int findMin(vector<int> &num) {
    return findMin(num, 0, num.size() - 1);
  }
private:
  int findMin(vector<int> &nums, int left, int right) {
    if (right == left) {
      return nums[left];
    }
    if (right == left + 1) {
      return std::min(nums[left], nums[right]);
    }

    int mid = left + (right - left) / 2;
    if (nums[right] > nums[left])
      return nums[left];
    else if (nums[right] == nums[left])
      return findMin(nums, left + 1, right);
    else if (nums[mid] >= nums[left])
      return findMin(nums, mid, right);
    else
      return findMin(nums, left, mid);
  }
};
