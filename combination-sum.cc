// http://www.lintcode.com/zh-cn/problem/combination-sum
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param candidates: A list of integers
   * @param target:An integer
   * @return: A list of lists of integers
   */
  vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    vector<int> cur_vec;
    std::sort(candidates.begin(), candidates.end());
    vector<vector<int>> ret;
    dfs(ret, candidates, cur_vec, 0, target, 0);

    // erase duplicate
    sort(ret.begin(), ret.end());
    ret.erase(unique(ret.begin(), ret.end()), ret.end());

    return ret;
  }
private:
  void dfs(vector<vector<int>> &ret, vector<int> &candidates, vector<int> &cur_vec, int cur, int target, int cur_sum) {
    if (cur_sum == target) {
      ret.push_back(cur_vec);
      return;
    }
    if (cur >= candidates.size())
      return;
    if (cur_sum + candidates[cur] <= target) {
      cur_vec.push_back(candidates[cur]);
      dfs(ret, candidates, cur_vec, cur, target, cur_sum + candidates[cur]);
      cur_vec.pop_back();

      dfs(ret, candidates, cur_vec, cur + 1, target, cur_sum);
    }
  }
};
