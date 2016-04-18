// http://www.lintcode.com/zh-cn/problem/subsets-ii

class Solution {
public:
  /**
   * @param S: A set of numbers.
   * @return: A list of lists. All valid subsets.
   */
  vector<vector<int> > subsetsWithDup(vector<int> &S) {
    sort(S.begin(), S.end());
    vector<vector<int> > ret;
    vector<int> path;
    dfs(S, S.begin(), path, ret);

    return ret;
  }
private:
  void dfs(const vector<int> &S, vector<int>::iterator start,
           vector<int> &path, vector<vector<int> > &ret) {
    ret.push_back(path);
    for (auto i = start; i < S.end(); i++) {
      if (i != start && *i == *(i - 1))
        continue;
      path.push_back(*i);
      dfs(S, i + 1, path, ret);
      path.pop_back();
    }
  }
};
