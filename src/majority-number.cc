// http://www.lintcode.com/zh-cn/problem/majority-number
#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param nums: A list of integers
   * @return: The majority number
   */
  int majorityNumber(vector<int> nums) {
    const unsigned size = nums.size();
    std::map<int, int> count_map;
    for (int i = 0; i < size; i++) {
      if (count_map.find(nums[i]) == count_map.end())
        count_map[nums[i]] = 1;
      else
        count_map[nums[i]]++;
    }
    for (std::map<int, int>::const_iterator iter = count_map.begin();
         iter != count_map.end(); iter++) {
      if (iter->second > size / 2)
        return iter->first;
    }
    return -1;
  }
};
