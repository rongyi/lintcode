// http://www.lintcode.com/zh-cn/problem/subsets

class Solution {
public:
  /**
   * @param S: A set of numbers.
   * @return: A list of lists. All valid subsets.
   */
  vector<vector<int> > subsets(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    vector<vector<int> > ret;
    vector<int> path;
    subsets(nums, path, 0, ret);

    return ret;
  }
private:
  void subsets(const vector<int> &s, vector<int> &path,
               int step, vector<vector<int> > &ret) {
    if (step == s.size()) {
      ret.push_back(path);
      return;
    }
    subsets(s, path, step + 1, ret);
    path.push_back(s[step]);
    subsets(s, path, step + 1, ret);
    path.pop_back();
  }
};
