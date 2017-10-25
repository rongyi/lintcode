// http://www.lintcode.com/zh-cn/problem/two-sum-input-array-is-sorted

#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;
class Solution {
public:
  /*
  * @param nums an array of Integer
  * @param target = nums[index1] + nums[index2]
  * @return [index1 + 1, index2 + 1] (index1 < index2)
  */
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> ret;
    int left = 0;
    int right = nums.size() - 1;
    while (left < right) {
      int cur_sum = nums[left] + nums[right];
      if (cur_sum == target) {
        ret.push_back(left + 1);
        ret.push_back(right + 1);
        return ret;
      } else if (cur_sum > target) {
        right--;
      } else {
        left++;
      }
    }
    ret.push_back(-1);
    ret.push_back(-1);
    return ret;
  }
};

int main() {
  vector<int> test{2, 7, 11, 15};
  Solution so;
  auto ret = so.twoSum(test, 9);
  cout << ret[0] << "  " << ret[1] << endl;
  return 0;
}
