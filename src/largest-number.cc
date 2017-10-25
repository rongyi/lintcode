// http://www.lintcode.com/zh-cn/problem/largest-number
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

bool cmp(const string &s1, const string &s2) {
  int i = 0;
  while (i < std::min(s1.length(), s2.length())) {
    if (s1[i] > s2[i])
      return true;
    else if (s1[i] < s2[i])
      return false;
    else
      i++;
  }
  // "89" "893" ==> 89 should before than 893
  if (i == s1.length()) {
    return !(s2[i] > s2[0]);
  }
  // "899" vs "89" ==> 899 should before 89
  if (i == s2.length()) {
    return (s1[i] > s1[0]);
  }
}

class Solution {
public:
  /**
   *@param num: A list of non negative integers
   *@return: A string
   */
  string largestNumber(vector<int> &num) {
    auto ret = std::accumulate(num.begin(), num.end(), 0);
    if (ret == 0)
      return "0";
    vector<string> ret_lst;
    for (auto i : num) {
      ret_lst.push_back(std::to_string(i));
    }
    std::sort(ret_lst.begin(), ret_lst.end(), cmp);
    std::stringstream ss;

    for (auto s : ret_lst) {
      ss << s;
    }

    return ss.str();
  }
};

int main() {
  Solution so;
  vector<int> test{1, 20, 23, 4, 8};
  auto ret = so.largestNumber(test);

  cout << ret << endl;
  return 0;
}
