// http://www.lintcode.com/zh-cn/problem/first-position-unique-character
#include <vector>
#include <iostream>
#include <string>
#include <set>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::set;



class Solution {
public:
  /**
   * @param s a string
   * @return it's index
   */
  int firstUniqChar(string& s) {
    if (s.empty())
      return -1;
    std::set<char> aux;
    for (int i = 0; i < s.size() - 1; i++) {
      if (aux.find(s[i]) != aux.end()) {
        continue;
      }

      string sub = s.substr(i+1);
      if (sub.find(s[i]) == string::npos) {
        return i;
      } else {
        aux.insert(s[i]);
      }
    }
    return aux.find(s[s.size() - 1]) == aux.end() ? s.size() - 1 : -1;
  }
};

int main()
{
  Solution so;
  string t = "{{;;lintcodelintcode}}";
  auto index = so.firstUniqChar(t);
  cout << index << endl;
  return 0;
}
