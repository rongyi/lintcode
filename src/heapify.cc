// http://www.lintcode.com/zh-cn/problem/heapify
#include <algorithm>
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
   * @param A: Given an integer array
   * @return: void
   */
  void heapify(vector<int> &nums) {
    // version 1: siftdown
    // if (nums.empty())
    //   return;
    // int start = nums.size() / 2;
    // for (int i = start; i >= 0; --i) {
    //   doHeapify(nums, i);
    // }

    // version 2: siftup
    for (int i = 0; i < nums.size(); i++) {
      siftup(nums, i);
    }
  }

private:
  void doHeapify(vector<int> &nums, int cur_index) {
    const int size = nums.size();
    int left_index = 2 * cur_index + 1;
    int right_index = 2 * cur_index + 2;
    while (left_index < size || right_index < size) {
      int left_val = (left_index < size) ? nums[left_index]
                                         : std::numeric_limits<int>::max();
      int right_val = (right_index < size) ? nums[right_index]
                                           : std::numeric_limits<int>::max();
      int next = (left_val <= right_val) ? left_index : right_index;

      // root should not be great than its children
      // in min heap
      if (nums[cur_index] >= nums[next]) {
        std::swap(nums[cur_index], nums[next]);
        cur_index = next;
        left_index = cur_index * 2 + 1;
        right_index = cur_index * 2 + 2;
      } else {
        break;
      }
    }
  }

  void siftup(vector<int> &nums, int k) {
    while (k != 0) {
      int parent = (k - 1) / 2;
      if (nums[k] > nums[parent])
        break;
      std::swap(nums[k], nums[parent]);
      k = parent;
    }
  }
};
