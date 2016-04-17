// http://www.lintcode.com/zh-cn/problem/regular-expression-matching

class Solution {
public:
  bool isMatch(const char *s, const char *p) {
    if (*p == '\0')
      return *s == '\0';

    // next not * meas strict match or dot match
    if (*(p + 1) != '*') {
      if (*p == *s || (*p == '.' && *s != '\0'))
        return isMatch(s + 1, p + 1);
      else
        return false;
    } else {
      while (*p == *s || (*p == '.' && *s != '\0')) {
        if (isMatch(s, p + 2))
          return true;
        s++;
      }
      return isMatch(s, p + 2);
    }
  }
};
