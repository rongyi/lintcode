// http://www.lintcode.com/zh-cn/problem/first-unique-number-in-stream

#include <bitset>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /*
  * @param : a continuous stream of numbers
  * @param : a number
  * @return: returns the first unique number
  */
  int firstUniqueNumberTLE(vector<int> nums, int number) {
    auto last_index = index(nums, number);
    if (last_index == -1) {
      return -1;
    }
    std::unordered_map<int, int> count;
    // number is not an index, it is a value in this vector
    for (int i = 0; i < last_index; ++i) {
      count[nums[i]]++;
    }

    for (int i = 0; i < last_index; ++i) {
      if (count[nums[i]] == 1) {
        return nums[i];
      }
    }
    return -1;
  }
private:
  int index(const vector<int> &nums, int n) {
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == n) {
        return i;
      }
    }
    return -1;
  }
};
