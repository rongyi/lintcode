// http://www.lintcode.com/zh-cn/problem/sort-letters-by-case
#include <vector>
#include <iostream>
#include <string>
#include <cctype>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param chars: The letters array you should sort.
   */
  void sortLetters(string &letters) {
    const int len = letters.length();
    int begin = 0;
    int end = len - 1;
    while (begin < end) {
      if (std::islower(letters[begin]))
        begin++;
      else if (std::isupper(letters[end]))
        end--;
      else {
        std::swap(letters[begin], letters[end]);
      }
    }
  }
};

int main()
{
  Solution so;
  std::string test{"helloWorD"};
  so.sortLetters(test);
  cout << test << endl;
  return 0;
}
