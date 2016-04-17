// http://www.lintcode.com/zh-cn/problem/longest-consecutive-sequence

class Solution {
public:
  /**
   * @param nums: A list of integers
   * @return an integer
   */
  int longestConsecutive(vector<int> &a) {
    int max_len = 0;
    const int len = a.size();
    std::map<int, bool> help_map;

    for (auto &i : a)
      help_map[i] = false;

    for (auto &i : a) {
      if (help_map[i])
        continue;
      int cur_max = 1;
      help_map[i] = true;

      for (int j = i + 1; help_map.find(j) != help_map.end(); j++) {
        cur_max++;
        help_map[j] = true;
      }
      for (int j = i - 1; help_map.find(j) != help_map.end(); j--) {
        cur_max++;
        help_map[j] = true;
      }
      if (cur_max > max_len)
        max_len = cur_max;

    }


    return max_len;
  }
};
