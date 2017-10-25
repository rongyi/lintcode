// http://www.lintcode.com/zh-cn/problem/k-sum-ii
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
   * @param A: an integer array.
   * @param k: a positive integer (k <= length(A))
   * @param target: a integer
   * @return a list of lists of integer
   */
  vector<vector<int>> kSumII(vector<int> A, int k, int target) {
    vector<vector<int>> ret;
    vector<int> cur;

    dosum(ret, cur, A, k, target, 0);

    return ret;
  }

private:
  void dosum(vector<vector<int>> &ret, vector<int> path, vector<int> nodes,
             int k, int remain, int index) {
    if (path.size() == k) {
      if (remain == 0) {
        ret.push_back(path);
      }
      return;
    }
    for (int i = index; i < nodes.size(); i++) {
      path.push_back(nodes[i]);
      dosum(ret, path, nodes, k, remain - nodes[i], i + 1);
      path.pop_back();
    }
  }
};
