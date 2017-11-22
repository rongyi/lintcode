// http://www.lintcode.com/zh-cn/problem/subsets
#include <vector>
#include <iostream>
#include <string>
#include <bitset>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::string;


class Solution {
public:
  /**
   * @param S: A set of numbers.
   * @return: A list of lists. All valid subsets.
   */
  vector<vector<int>> subsets(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    vector<vector<int>> ret;
    vector<int> path;
    subsets(nums, path, 0, ret);

    return ret;
  }

private:
  void subsets(const vector<int> &s, vector<int> &path, int step,
               vector<vector<int>> &ret) {
    if (step == s.size()) {
      ret.push_back(path);
      return;
    }
    // without current node
    subsets(s, path, step + 1, ret);

    // with current node
    path.push_back(s[step]);
    subsets(s, path, step + 1, ret);
    path.pop_back();
  }
};

int main()
{
  Solution so;
  vector<int> test{1, 2, 3};
  auto ret = so.subsets(test);
  for (auto v: ret) {
    for (auto i : v) {
      cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}
