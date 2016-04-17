// http://www.lintcode.com/zh-cn/problem/wildcard-matching

class Solution {
public:
  /**
   * @param s: A string
   * @param p: A string includes "?" and "*"
   * @return: A boolean
   */
  bool isMatch(const char *s, const char *p) {
    bool has_star = false;
    const char *str;
    const char *ptr;

    for (str = s, ptr = p; *str != '\0'; str++, ptr++) {
      switch (*ptr) {
      case '?':
        break;
      case '*':
        has_star = true;
        s = str, p = ptr;
        while (*p == '*')
          p++;
        if (*p == '\0')
          return true;
        str = s - 1;
        ptr = p - 1;
        break;
      default:
        if (*str != *ptr) {
          if (!has_star)
            return false;
          s++;
          str = s - 1;
          ptr = p - 1;
        }
      }
    }
    while (*ptr == '*')
      ptr++;
    return (*ptr == '\0');
  }
};
