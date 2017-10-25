// http://www.lintcode.com/zh-cn/problem/longest-common-prefix

class Solution {
public:
  /**
   * @param strs: A list of strings
   * @return: The longest common prefix
   */
  string longestCommonPrefix(vector<string> &strs) {
    // write your code here
    if (strs.empty())
      return "";
    for (unsigned i = 0; i < strs[0].size(); ++i) {
      for (unsigned j = 1; j < strs.size(); ++j) {
        if (strs[j][i] != strs[0][i])
          return strs[0].substr(0, i);
      }
    }
    return strs[0];
  }
};
