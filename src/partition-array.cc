// http://www.lintcode.com/zh-cn/problem/partition-array

#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  int partitionArray(vector<int> &nums, int k) {
    const int n = nums.size();
    if (n == 0)
      return 0;
    int begin = 0;
    int end = n - 1;
    while (begin <= end) {
      if (nums[begin] < k) {
        begin++;
      } else if (nums[end] >= k) {
        end--;
      } else {                  // swap
        std::swap(nums[begin++], nums[end--]);
      }
    }
    return begin;
  }
};

int main()
{
  vector<int> test{7, 7, 9, 8, 6, 6, 8, 7, 9, 8, 6, 6};
  Solution so;
  auto ret = so.partitionArray(test, 10);
  cout << ret << endl;
  return 0;
}
