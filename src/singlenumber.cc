#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int ret = 0;
    for (auto &i : nums) {
      ret ^= i;
    }
    return ret;
  }
};


int main()
{
  vector<int> test{1, 2, 3, 1, 2, 3, 4};
  auto ret = Solution().singleNumber(test);
  cout << ret << endl;
  return 0;
}
