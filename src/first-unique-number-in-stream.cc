// http://www.lintcode.com/zh-cn/problem/first-unique-number-in-stream

#include <bitset>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <algorithm>

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
  int firstUniqueNumber(vector<int> nums, int number) {
    const int n = nums.size();
    bool has_number = false;
    int number_index = -1;

    // number is not an index, it is a value in this vector
    for (int i = 0; i < n; ++i) {
      if (nums[i] == number) {
        has_number = true;
        number_index = i;
        break;
      }
    }

    if (!has_number) {
      return -1;
    }

    std::unordered_map<int, int> count;
    for (int i = 0; i <= number_index; i++) {
      count[nums[i]]++;
    }

    for (int i = 0; i <= number_index; ++i) {
      if (count[nums[i]] == 1) {
        return nums[i];
      }
    }

    return -1;
  }
};

int main()
{
  return 0;
}
