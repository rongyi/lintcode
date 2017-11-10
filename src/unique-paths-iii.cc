// http://www.lintcode.com/zh-cn/problem/unique-paths-iii
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /*
  * @param : an array of arrays
  * @return: the sum of all unique weighted paths
  */
  int uniqueWeightedPaths(vector<vector<int>> &grid) {
    if (grid.empty() || grid[0].empty()) {
      return 0;
    }
    const int m = grid.size();
    const int n = grid[0].size();
    // or we can put pair as key, I am lazy
    // https://stackoverflow.com/questions/32685540/c-unordered-map-with-pair-as-key-not-compiling
    std::unordered_map<string, std::unordered_set<int>> cache;

    cache[key(1, 1)] = std::unordered_set<int>{grid[0][0]};

    int ret = 0;
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        // ignore the origin point
        if (i == 1 && j == 1) {
          continue;
        }
        std::unordered_set<int> newset;
        // please note i and j are taken!
        for (auto v : cache[key(i - 1, j)]) {
          newset.insert(v + grid[i - 1][j - 1]);
        }
        for (auto v : cache[key(i, j - 1)]) {
          newset.insert(v + grid[i - 1][j - 1]);
        }
        cache[key(i, j)] = newset;
        if (i == m && j == n) {
          for (auto v : cache[key(i, j)]) {
            ret += v;
          }
        }
      }
    }
    return ret;
  }

private:
  string key(int i, int j) {
    return std::to_string(i) + ":" + std::to_string(j);
  }
};

int main() {
  Solution so;
  vector<vector<int>> t{vector<int>{1, 1, 2}, vector<int>{1, 2, 3},
                        vector<int>{3, 2, 4}};
  auto ret = so.uniqueWeightedPaths(t);
  cout << ret << endl;
  return 0;
}
