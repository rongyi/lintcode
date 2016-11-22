// http://www.lintcode.com/zh-cn/problem/kth-smallest-number-in-sorted-matrix
#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <map>

using std::vector;
using std::cout;
using std::endl;
using std::string;



class Solution {
public:
  /**
   * @param matrix: a matrix of integers
   * @param k: an integer
   * @return: the kth smallest number in the matrix
   */
  int kthSmallest(vector<vector<int> > &matrix, int k) {
    if (k <= 0 || matrix.empty())
      return 0;

    const int m = matrix.size();
    const int n = matrix[0].size();

    std::priority_queue<std::pair<int, std::pair<int, int>>,
      std::vector<std::pair<int, std::pair<int, int>>>,
      std::greater<std::pair<int, std::pair<int, int>>>> pq;
    std::map<std::pair<int, int>, bool> visited;
    pq.push(std::make_pair(matrix[0][0], std::make_pair(0, 0)));
    visited[std::make_pair(0, 0)] = true;

    while (k--) {
      auto cur = pq.top();
      if (k == 0) {
        return cur.first;
      }
      pq.pop();
      int downx = cur.second.first + 1;
      int downy = cur.second.second;
      if (downx < m &&
          visited.find(std::make_pair(downx, downy)) == visited.end()) {
        pq.push(std::make_pair(matrix[downx][downy], std::make_pair(downx, downy)));
        visited[std::make_pair(downx, downy)] = true;
      }

      int rightx = cur.second.first;
      int righty = cur.second.second + 1;
      if (righty < n &&
          visited.find(std::make_pair(rightx, righty)) == visited.end()) {
        pq.push(std::make_pair(matrix[rightx][righty], std::make_pair(rightx, righty)));
        visited[std::make_pair(rightx, righty)] = true;
      }
    }
    return -1;
  }
};
int main()
{
  Solution so;
  vector<int> test_inner{1, 2, 3, 4, 5};
  vector<vector<int>> test = {test_inner};
  auto ret = so.kthSmallest(test, 3);
  cout << ret << endl;
  return 0;
}
