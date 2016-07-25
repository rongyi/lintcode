// http://www.lintcode.com/zh-cn/problem/subarray-sum
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
   * @param nums: A list of integers
   * @return: A list of integers includes the index of the first number
   *          and the index of the last number
   */
  vector<int> subarraySum(vector<int> nums){
    vector<int> ret;
    if (nums.empty()) {
      return ret;
    }

    if (nums.size() == 1) {
      if (nums[0] != 0) {
        return ret;
      }
      ret.push_back(0);
      ret.push_back(0);
      return ret;
    }

    const int n = nums.size();

    // brute force to test all the sub array
    for (int i = 0; i < n; i++) {
      int sum = nums[i];
      // the element may be zero
      if (sum == 0) {
        ret.push_back(i);
        ret.push_back(i);
        return ret;
      }
      for (int j = i + 1; j < n; j++) {
        sum += nums[j];
        if (sum == 0) {
          ret.push_back(i);
          ret.push_back(j);
          return ret;
        }
      }
    }

    return ret;
  }
};

int main(int argc, char *argv[])
{
  vector<int> test{-5, 10, 5, -3, 1, 1, 1, -2, 3, -4};

  Solution so;
  auto ret = so.subarraySum(test);
  cout << ret.size() << endl;

  return 0;
}
