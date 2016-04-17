// http://www.lintcode.com/zh-cn/problem/anagrams

class Solution {
public:
  /**
   * @param strs: A list of strings
   * @return: A list of strings
   */
  vector<string> anagrams(vector<string> &strs) {
    // write your code here
    unordered_map<string, vector<string> > group;
    for (const auto &s :strs) {
      string key = s;
      std::sort(key.begin(), key.end());
      group[key].push_back(s);
    }

    vector<string> ret;
    for (auto it = group.cbegin(); it != group.end(); it++) {
      if (it->second.size() > 1)
        ret.insert(ret.end(), it->second.begin(), it->second.end());
    }
    return ret;

  }
};
