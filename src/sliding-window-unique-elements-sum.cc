// http://www.lintcode.com/zh-cn/problem/sliding-window-unique-elements-sum
#include <algorithm>
#include <bitset>
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
  /*
  * @param : the given array
  * @param : the window size
  * @return: the sum of the count of unique elements in each window
  */
  int slidingWindowUniqueElementsSum(vector<int> nums, int k) {
    int n = nums.size();
    std::map<int, int> record;
    for (int i = 0; i < std::min(k, n); i++)
      record[nums[i]]++;
    vector<int> rets;
    rets.push_back(count(record));

    for (int i = k; i < n; i++) {
      int temp = 0;
      record[nums[i - k]]--;
      record[nums[i]]++;
      // 进来的和出去的值是否一样，如果一样，进出抵消，之前值是多少就多少
      if (nums[i - k] != nums[i]) {
        // 去掉一个重复带来一个unique
        if (record[nums[i - k]] == 1)
          temp++;
        // 走了一个unique
        else if (record[nums[i - k]] == 0)
          temp--;

        // 新增一个unique
        if (record[nums[i]] == 1)
          temp++;
        // 带来一个重复
        else if (record[nums[i]] == 2)
          temp--;
      }
      rets.push_back(rets[i - k] + temp);
    }
    int ret = 0;
    for (int x : rets)
      ret += x;

    return ret;
  }
  int count(std::map<int, int> &record) {
    int num = 0;
    for (auto x : record) {
      if (x.second == 1)
        num++;
    }
    return num;
  }
};

int main() {
  Solution so;
  std::vector<int> test{1, 1, 3, 4};
  auto ret = so.slidingWindowUniqueElementsSum(test, 3);
  cout << ret << endl;
  return 0;
}
