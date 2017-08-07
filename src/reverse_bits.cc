#include <vector>
#include <iostream>
#include <string>
#include <bitset>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {

public:
  int reverseBits(int n) {
    int left = 0;
    int right = 31;
    while (left < right) {
      int x = (n >> left) & 1;
      int y = (n >> right) & 1;

      if (x != y) {
        n ^= (1 << left) | (1 << right);
      }
      ++left;
      --right;
    }
    return n;
  }
};


int main()
{
  Solution so;

  int test = 43261596;
  auto ret = so.reverseBits(test);
  cout << ret << endl;
  return 0;
}
