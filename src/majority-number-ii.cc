// http://www.lintcode.com/zh-cn/problem/majority-number-ii
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;

class Solution {
public:
  /**
   * @param nums: A list of integers
   * @return: The majority number occurs more than 1/3.
   */
  int majorityNumber(vector<int> nums) {
    const int n = nums.size();
    const int pivot = n / 3;
    if (n == 0)
      return -1;
    if (pivot == 0)
      return nums[0];
    unordered_map<int, int> count_map;
    for (auto i : nums) {
      if (count_map.find(i) == count_map.end()) {
        count_map[i] = 1;
      } else {
        ++count_map[i];
      }
    }

    for (auto iter = count_map.cbegin();
         iter != count_map.cend();
         iter++) {
      if (iter->second > pivot)
        return iter->first;
    }
    return -1;
  }
};

int main()
{
  Solution so;
  vector<int> test{99,2,99,2,99,3,3};
  auto ret = so.majorityNumber(test);
  cout << ret << endl;
  return 0;
}
