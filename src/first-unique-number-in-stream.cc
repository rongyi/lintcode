// http://www.lintcode.com/zh-cn/problem/first-unique-number-in-stream

#include <bitset>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <list>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
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
    std::map<int, int> index_map;
    for (int i = 0; i <= number_index; i++) {
      index_map[nums[i]] = i;
    }

    for (int i = 0; i <= number_index; ++i) {
      if (index_map[nums[i]] == i) {
        return nums[i];
      } else {
        index_map[nums[i]] = i;
      }
    }

    return -1;
  }

  /*
  * @param : a continuous stream of numbers
  * @param : a number
  * @return: returns the first unique number
  */
  int firstUniqueNumberTLE(vector<int> nums, int number) {
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

    std::unordered_map<int, int> index_map;
    for (int i = 0; i <= number_index; i++) {
      // count[nums[i]]++;
      index_map[nums[i]] = i;
    }

    for (int i = 0; i <= number_index; ++i) {
      if (index_map[nums[i]] == i) {
        return nums[i];
      } else {
        index_map[nums[i]] = i;
      }
    }

    return -1;
  }
};

int main()
{
  vector<int> test{1,2,2,1,2,4,4,5,6,5,7,6,8};
  Solution so;
  auto i = so.firstUniqueNumber(test, 8);
  cout << i << endl;
  return 0;
}
