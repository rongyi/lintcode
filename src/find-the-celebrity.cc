// http://www.lintcode.com/zh-cn/problem/find-the-celebrity
#include <vector>
#include <iostream>
#include <string>
#include <set>

using std::vector;
using std::cout;
using std::endl;
using std::string;

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
  /**
   * @param n a party with n people
   * @return the celebrity's label or -1
   */
  int findCelebrity(int n) {
    std::set<int> normal_set;
    for (int i = 0; i < n; i++) {
      // i is normal person
      if (normal_set.find(i) != normal_set.end()) {
        continue;
      }
      for (int j = 0; j < n; j++) {
        if (i == j) {
          continue;
        }
        // i is normal person
        if (knows(i, j)) {
          normal_set.insert(i);
        }
        // so j is a normal person too
        if (knows(j, i)) {
          normal_set.insert(j);
        }
      }
    }
    for (int i = 0; i < n;) {
      // a celebrity candidate, so every one must know him/her
      if (normal_set.find(i) == normal_set.end()) {
        for (int j = 0; j < n; j++) {
          if (i == j) {
            continue;
          }
          // i is not celebrity
          if (!knows(j, i)) {
            goto next;
          }
        }
        return i;
      }
    next:
      i++;
    }
    return -1;
  }
};
