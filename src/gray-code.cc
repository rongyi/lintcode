// http://www.lintcode.com/zh-cn/problem/gray-code/

#include <vector>
using std::vector;

class Solution {
public:
  /**
   * @param n a number
   * @return Gray code
   */
  vector<int> grayCode(int n) {
    vector<int> ret;
    if (n < 0)
      return ret;
    const size_t size = 1 << n;
    ret.reserve(size);
    for (size_t i = 0; i < size; ++i) {
      ret.push_back(binary_to_gray(i));
    }
    return ret;
  }

private:
  unsigned int binary_to_gray(unsigned int n) {
    return n ^ (n >> 1);
  }
};
