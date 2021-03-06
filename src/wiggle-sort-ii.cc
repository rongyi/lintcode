// http://www.lintcode.com/zh-cn/problem/wiggle-sort-ii
#include <algorithm>
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
   * @param nums a list of integer
   * @return void
   */
  void wiggleSort(vector<int> &nums) {
    vector<int> tmp = nums;
    std::sort(tmp.begin(), tmp.end());
    const int n = nums.size();
    int k = (n + 1) / 2;
    int j = n;
    for (int i = 0; i < n; i++) {
      nums[i] = i & 1 ? tmp[--j] : tmp[--k];
    }
  }
};

int main() {
  Solution so;
  vector<int> test{3, 5, 2, 1, 6, 4};
  so.wiggleSort(test);
  for (auto i : test)
    cout << i << " ";
  cout << endl;
  return 0;
}
