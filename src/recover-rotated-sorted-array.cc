// http://www.lintcode.com/zh-cn/problem/recover-rotated-sorted-array
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  void recoverRotatedSortedArray(vector<int> &nums) {
    if (nums.empty())
      return;
    const int n = nums.size();
    int i = 0;
    for (; i < n - 1; i++) {
      // find the pivot
      if (nums[i] > nums[i + 1]) {
        break;
      }
    }
    for (int j = 0; j <= i; j++) {
      nums.push_back(nums[j]);
    }
    nums.erase(nums.begin(), nums.begin() + i + 1);

    // for (auto i: nums)
    //   cout << i << " ";
    // cout << endl;
  }
};

int main() {
  Solution so;
  vector<int> test{4, 1, 2, 3};
  so.recoverRotatedSortedArray(test);

  return 0;
}
