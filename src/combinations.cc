// http://www.lintcode.com/zh-cn/problem/combinations
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
   * @param n: Given the range of numbers
   * @param k: Given the numbers of combinations
   * @return: All the combinations of k numbers out of 1..n
   */
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ret;
    vector<int> cur;
    combine(ret, cur, 1, n, k);
    return ret;
  }
  void combine(vector<vector<int>> &ret, vector<int> cur, int index, int n,
               int k) {
    if (cur.size() == k) {
      ret.push_back(cur);
      return;
    }
    // cur.size > k may never met
    if (index > n || cur.size() > k)
      return;
    // dont choose current node
    combine(ret, cur, index + 1, n, k);
    // choose current node
    cur.push_back(index);
    combine(ret, cur, index + 1, n, k);
  }
};

int main() {
  Solution so;
  auto ret = so.combine(4, 2);
  for (auto &v : ret) {
    for (auto i : v) {
      cout << i << " ";
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}
