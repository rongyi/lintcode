// http://www.lintcode.com/zh-cn/problem/majority-number-iii
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;

class Solution {
public:
  /**
   * @param nums: A list of integers
   * @param k: As described
   * @return: The majority number
   */
  int majorityNumber(vector<int> nums, int k) {
    if (k <= 0)
      return -1;
    if (nums.empty())
      return -1;
    const int n = nums.size();
    const int pivot = n / k;
    if (pivot == 0)
      return nums[0];
    unordered_map<int, int> aux;
    for (auto i : nums) {
      if (aux.find(i) == aux.end())
        aux[i] = 1;
      else
        ++aux[i];
    }
    for (auto iter = aux.cbegin(); iter != aux.cend(); iter++) {
      if (iter->second > pivot)
        return iter->first;
    }
    return -1;
  }
};

int main() {
  Solution so;
  vector<int> test{2, 2, 5, 1};
  auto ret = so.majorityNumber(test, 3);
  cout << ret << endl;
  return 0;
}
