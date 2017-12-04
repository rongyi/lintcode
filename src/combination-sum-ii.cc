// http://www.lintcode.com/zh-cn/problem/combination-sum-ii
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param num: Given the candidate numbers
   * @param target: Given the target number
   * @return: All the combinations that sum to target
   */
  vector<vector<int>> combinationSum2(vector<int> &num, int target) {
    vector<int> cur_vec;
    std::sort(num.begin(), num.end());
    vector<vector<int>> ret;
    // dfs(ret, num, cur_vec, 0, target, 0);
    dfs2(ret, num, cur_vec, 0, target);

    return ret;
  }

private:
  void dfs2(vector<vector<int>> &ret, vector<int> &num, vector<int> &cur_vec,
            int cur_index, int target) {
    if (target < 0) {
      return;
    } else if (target == 0) {
      ret.push_back(cur_vec);
      return;
    }
    for (int i = cur_index; i < num.size(); i++) {
      // in case duplicate
      if (i > cur_index && num[i] == num[i - 1])
        continue;
      cur_vec.push_back(num[i]);
      // 和之前的一比较这里index就往上走了
      dfs2(ret, num, cur_vec, i + 1, target - num[i]);
      cur_vec.pop_back();
    }
  }
};
