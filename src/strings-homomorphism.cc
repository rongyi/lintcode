// http://www.lintcode.com/zh-cn/problem/strings-homomorphism
#include <algorithm>
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
   * @param s a string
   * @param t a string
   * @return true if the characters in s
   * can be replaced to get t or false
   */
  bool isIsomorphic(string &s, string &t) {
    vector<int> sc;
    vector<int> tc;
    std::unordered_map<char, int> sd;
    std::unordered_map<char, int> td;

    for (auto &c : s) {
      sd[c]++;
    }
    for (auto &c : t) {
      td[c]++;
    }

    for (auto iter = sd.begin(); iter != sd.end(); iter++) {
      sc.push_back(iter->second);
    }

    for (auto iter = td.begin(); iter != td.end(); iter++) {
      tc.push_back(iter->second);
    }
    std::sort(sc.begin(), sc.end());
    std::sort(tc.begin(), tc.end());

    for (int i = 0; i < sc.size(); ++i) {
      if (sc[i] != tc[i])
        return false;
    }

    return true;
  }
};
