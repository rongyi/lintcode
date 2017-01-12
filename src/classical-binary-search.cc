// http://www.lintcode.com/zh-cn/problem/classical-binary-search
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
   * @param A an integer array sorted in ascending order
   * @param target an integer
   * @return an integer
   */
  int findPosition(vector<int>& a, int target) {
    if (a.empty())
      return -1;
    const int len = a.size();
    int left = 0;
    int right = len;
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (a[mid] == target) {
        return mid;
      } else if (target > a[mid]) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    return -1;
  }
};
int main()
{
  auto so = Solution();
  vector<int> test{1, 2, 2, 4, 5, 5};
  auto ret = so.findPosition(test, 2);
  cout << ret << endl;
  return 0;
}
