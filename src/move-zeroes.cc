// http://www.lintcode.com/zh-cn/problem/move-zeroes
#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
  /**
   * @param nums an integer array
   * @return nothing, do this in-place
   */
  void moveZeroes(vector<int>& nums) {
    auto size = nums.size();
    unsigned i = 0;
    for (auto iter = nums.begin(); iter != nums.end() && i < size; i++) {
      if (*iter == 0) {
        iter = nums.erase(iter);
        nums.push_back(0);
      } else {
        iter++;
      }
    }
  }
};


// int main(int argc, char *argv[])
// {
//   std::vector<int> *test = new std::vector<int>{-1, 2, -3, 4, 0, 1, 0, -2, 0, 0, 1};
//   Solution so;
//   so.moveZeroes(*test);
//   for (auto i: *test) {
//     std::cout << i << std::endl;
//   }
//   delete test;
//   return 0;
// }
