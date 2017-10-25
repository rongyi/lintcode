// http://www.lintcode.com/zh-cn/problem/continuous-subarray-sum
#include <cctype>
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
   * @param A an integer array
   * @return  A list of integers includes the index of
   *          the first number and the index of the last number
   */
  vector<int> continuousSubarraySum(vector<int> &A) {
    int cur_sum = 0;
    int max_sum = INT_MIN;
    vector<int> ret;

    int cur_start = 0;
    int start = 0;
    int end = 0;

    for (int i = 0; i < A.size(); i++) {
      if (cur_sum < 0) {
        cur_sum = A[i];
        cur_start = i;
      } else {
        cur_sum += A[i];
      }

      if (cur_sum > max_sum) {
        max_sum = cur_sum;
        start = cur_start;
        end = i;
      }
    }

    ret.push_back(start);
    ret.push_back(end);

    return ret;
  }
};
