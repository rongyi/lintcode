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
  bool palindromeNumber(int num) {
    string s = std::to_string(num);
    string rs = s;
    std::reverse(rs.begin(), rs.end());

    return s == rs;
  }
};
