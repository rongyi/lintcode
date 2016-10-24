// http://www.lintcode.com/zh-cn/problem/longest-increasing-continuous-subsequence
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
   * @param A an array of Integer
   * @return  an integer
   */
  int longestIncreasingContinuousSubsequence(vector<int>& A) {
    if (A.empty())
      return 0;
    const int m = A.size();
    vector<vector<bool>> dpdes(m, vector<bool>(m, false));
    vector<vector<bool>> dpasc(m, vector<bool>(m, false));
    for (int i = 0; i < m; i++) {
      dpdes[i][i] = true;
      dpasc[i][i] = true;
    }
    for (int i = 0; i < m; i++) {
      for (int j = i + 1; j < m; j++) {
        if (dpdes[i][j - 1] && A[j] < A[j - 1]) {
          dpdes[i][j] = true;
        }
        if (dpasc[i][j - 1] && A[j] > A[j - 1]) {
          dpasc[i][j] = true;
        }
      }
    }

    auto ret = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < m; j++) {
        if (dpdes[i][j]) {
          ret = std::max(j - i + 1, ret);
        }
        if (dpasc[i][j]) {
          ret = std::max(j - i + 1, ret);
        }
      }
    }
    return ret;
  }
};

int main()
{
  Solution so;
  vector<int> test{5, 4, 2, 1, 3};
  auto ret = so.longestIncreasingContinuousSubsequence(test);
  cout << ret << endl;
  return 0;
}
