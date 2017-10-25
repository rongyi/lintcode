// http://www.lintcode.com/zh-cn/problem/triangle-count
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
   * @param S: A list of integers
   * @return: An integer
   */
  int triangleCount(vector<int> &s) {
    if (s.size() < 3) {
      return 0;
    }
    std::sort(s.begin(), s.end());
    const int n = s.size();
    int ret = 0;
    for (int i = 0; i < n; i++) {
      int left = 0;
      int right = i - 1;
      while (left < right) {
        if (s[left] + s[right] > s[i]) {
          ret += (right - left);
          right--;
        } else {
          left++;
        }
      }
    }
    return ret;
  }
};

int main() {
  Solution so;
  vector<int> test{4, 4, 4, 4};
  auto ret = so.triangleCount(test);
  cout << ret << endl;
  return 0;
}
