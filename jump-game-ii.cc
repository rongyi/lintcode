// http://www.lintcode.com/zh-cn/problem/jump-game-ii
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
   * @param a: a list of lists of integers
   * @return: An integer
   */
  int jump(vector<int> a) {
    int ret = 0;
    int last = 0;
    int cur = 0;
    for (int i = 0; i < a.size(); i++) {
      if (i > last) {
        last = cur;
        ++ret;
      }
      cur = std::max(cur, i + a[i]);
    }

    return ret;
  }
};

int main()
{
  vector<int> input{2, 3, 1, 1, 4};
  Solution so;
  auto ret = so.jump(input);
  cout << ret << endl;
  return 0;
}
