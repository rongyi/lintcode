#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {

public:
  int singleNumber(vector<int> &nums) {
    vector<int> count(sizeof(int) * 8, 0);

    int ret = 0;
    for (auto &n : nums) {
      for (int i = 0; i < 32; ++i) {
        count[i] += (n >> i) & 1;
        count[i] %= 3;
      }
    }

    for (int i = 0; i < 32; ++i) {
      ret |= (count[i] << i);
    }
    return ret;
  }
};

int main() {
  vector<int> nums{1, 2, 3, 1, 2, 3, 1, 2, 3, 7};
  auto ret = Solution().singleNumber(nums);
  cout << ret << endl;
  return 0;
}
