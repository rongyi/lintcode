#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param num a positive number
   * @return true if it's a palindrome or false
   */
  bool palindromeNumberStringMethod(int num) {
    string s = std::to_string(num);
    string rs = s;
    std::reverse(rs.begin(), rs.end());

    return s == rs;
  }

  // math way
  bool palindromeNumber(int num) {
    int count = 1;
    int copy = num;
    while (num /= 10) {
      count *= 10;
    }

    num = copy;

    while (num) {
      int left = num / count;
      int right = num % 10;
      if (left != right) {
        return false;
      }

      num = num % count;
      num /= 10;
      count /= 100;
    }

    return true;
  }
};

int main()
{
  Solution so;
  auto ret = so.palindromeNumber(122221);
  cout << ret << endl;
  return 0;
}
