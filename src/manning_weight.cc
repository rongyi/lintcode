#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {

public:
  int hammingWeight(int n) {
    // int ret = 0;
    // for (int i = 0; i < 32; ++i) {
    //   ret += n & 1;
    //   n >>= 1;
    // }
    // return ret;

    int ret = 0;
    while (n != 0) {
      ++ret;
      n &= n - 1;
    }
    return ret;
  }
};


int main()
{
  Solution so;
  auto ret = so.hammingWeight(11);
  cout << ret << endl;
  return 0;
}
