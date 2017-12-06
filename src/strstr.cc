// http://www.lintcode.com/zh-cn/problem/strstr
#include <vector>
#include <iostream>
#include <string>
#include <bitset>

using std::vector;
using std::cout;
using std::endl;
using std::string;


class Solution {
public:
  /**
   * Returns a index to the first occurrence of target in source,
   * or -1  if target is not part of source.
   * @param source string to be scanned.
   * @param target string containing the sequence of characters to match.
   */
  int strStr1(const char *haystack, const char *needle) {
    if (!haystack || !needle)
      return -1;
    // empty string needle
    if (!*needle)
      return 0;
    const char *p1;
    const char *p2;
    const char *p1_advance = haystack;
    for (p2 = &needle[1]; *p2; ++p2) {
      p1_advance++;
    }
    for (p1 = haystack; *p1_advance; p1_advance++) {
      char *p1_old = (char *)p1;
      p2 = needle;
      while (*p1 && *p2 && *p1 == *p2) {
        p1++;
        p2++;
      }
      if (!*p2)
        return p1_old - haystack;

      p1 = p1_old + 1;
    }
    return -1;
  }

  int strStr(const char *haystack, const char *needle) {
    if (!haystack || !needle) {
      return -1;
    }
    const string h(haystack);
    const string n(needle);

    if (n.empty()) {
      return 0;
    }
    const int end = h.size() - n.size() + 1;
    for (int i = 0; i < end; ++i) {
      int j = i;
      int k = 0;
      while (j < h.size() && k < n.size() && h[j] == n[k]) {
        j++;
        k++;
      }
      if (k == n.size()) {
        return i;
      }
    }
    return -1;
  }
};
