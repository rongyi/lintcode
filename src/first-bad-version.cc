// http://www.lintcode.com/zh-cn/problem/first-bad-version
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

/**
 * class SVNRepo {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use SVNRepo::isBadVersion(k) to judge whether
 * the kth code version is bad or not.
 */

class SVNRepo {
public:
  static bool isBadVersion(int k);
};

class Solution {
public:
  /**
   * @param n: An integers.
   * @return: An integer which is the first bad version.
   */
  int findFirstBadVersion(int n) {
    int begin = 1;
    int end = n;
    while (begin < end) {
      const int mid = begin + (end - begin) / 2;
      // if mid is bad we search it before, mid may also be a bad commit
      if (SVNRepo::isBadVersion(mid)) {
        end = mid;
      } else {
        // bad commit must start *after* mid
        begin = mid + 1;
      }
    }
    return begin;
  }
};
