// http://www.lintcode.com/zh-cn/problem/remove-duplicates-from-sorted-array-ii
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param A: a list of integers
   * @return : return an integer
   */
  int removeDuplicates(vector<int> &nums) {
    if (nums.size() <= 2)
      return nums.size();

    int index = 2;
    for (int i = 2; i < nums.size(); i++) {
      if (nums[i] != nums[index - 2])
        nums[index++] = nums[i];
    }

    return index;
  }
};

int main() {
  Solution so;
  vector<int> test{1, 2, 2, 3, 3, 3};
  auto ret = so.removeDuplicates(test);
  cout << ret << endl;
  return 0;
}
