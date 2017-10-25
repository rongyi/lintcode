// http://www.lintcode.com/zh-cn/problem/length-of-last-word/

class Solution {
public:
  /**
   * @param s A string
   * @return the length of last word
   */
  int lengthOfLastWord(string &str) {
    // Write your code here
    const char *s = str.c_str();
    int len = 0;
    while (*s) {
      if (*s++ != ' ')
        len++;
      else if (*s && *s != ' ') // note, no s++, so the count will be added
                                // in the next round
        len = 0;
    }
    return len;
  }
};
