// http://www.lintcode.com/zh-cn/problem/longest-words/

class Solution {
public:
  /**
   * @param dictionary: a vector of strings
   * @return: a vector of strings
   */
  vector<string> longestWords(vector<string> &dictionary) {
    vector<string> ret;
    int max_len = 0;
    for (int i = 0; i < dictionary.size(); i++) {
      const std::string &cur = dictionary[i];
      if (cur.length() == max_len) {
        // max_len = cur.length();
        ret.push_back(cur);
      } else if (cur.length() > max_len) {
        ret.clear();
        max_len = cur.length();
        ret.push_back(cur);
      }
    }
    return ret;
  }
};
