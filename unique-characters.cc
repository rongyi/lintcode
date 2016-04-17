// http://www.lintcode.com/zh-cn/problem/unique-characters

#include <set>
using namespace std;
class Solution {
public:
  /**
   * @param str: a string
   * @return: a boolean
   */
  bool isUnique(string &str) {
    std::set<char> char_set;
    for (int i = 0; i < str.size(); i++) {
      if (char_set.find(str[i]) == char_set.end()) {
        char_set.insert(str[i]);
      } else {
        return false;
      }
    }
    return true;
  }
};
