#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param s a string which consists of lowercase or uppercase letters
   * @return the length of the longest palindromes that can be built
   */
  int longestPalindrome(string &s) {
    std::unordered_map<char, int> stat;
    for (auto &c : s) {
      stat[c]++;
    }
    bool has_odd = false;
    int ret = 0;
    for (auto iter = stat.cbegin(); iter != stat.cend(); iter++) {
      // const char c = iter->first;
      const int count = iter->second;
      if (count & 0x01) {
        ret += (count - 1);
        if (!has_odd) {
          ret += 1;
          has_odd = true;
        }
      } else {
        ret += count;
      }
    }
    return ret;
  }
};
