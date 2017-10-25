// http://www.lintcode.com/zh-cn/problem/compare-strings
#include <cctype>
#include <iostream>
#include <set>
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
   * @param A: A string includes Upper Case letters
   * @param B: A string includes Upper Case letter
   * @return:  if string A contains all of the characters in B return true
   *           else return false
   */
  bool compareStrings(string A, string B) {
    std::unordered_map<char, int> count_dict;

    for (auto c : A) {
      if (count_dict.find(std::toupper(c)) == count_dict.end())
        count_dict[std::toupper(c)] = 1;
      else
        count_dict[std::toupper(c)]++;
    }
    for (auto c : B) {
      auto sret = count_dict.find(std::toupper(c));
      if (sret == count_dict.end())
        return false;
      count_dict[std::toupper(c)]--;
      if (!count_dict[std::toupper(c)])
        count_dict.erase(std::toupper(c));
    }

    return true;
  }
};
