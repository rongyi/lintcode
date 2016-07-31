// http://www.lintcode.com/zh-cn/problem/continuous-subarray-sum
#include <vector>
#include <iostream>
#include <string>
#include <cctype>

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
  vector<int> continuousSubarraySum(vector<int>& A) {
    int ld = 0;
    int rd = 0;
    int lt = 0;
    int rt = 0;
    int sum = 0;
    int ret = INT_MIN;
    vector<int> ret_lst;

    for (int i = 0; i < A.size(); i++) {
      if (sum < 0) {
        sum = A[i];
        if (sum > ret) {
          ret = sum;
          lt = rt = i;
        }
        ld = rd = i;
      } else {
        sum += A[i];
        rd = i;
        if (sum > ret) {
          ret = sum;
          lt = ld;
          rt = rd;
        }
      }
    }
    ret_lst.push_back(lt);
    ret_lst.push_back(rt);

    return ret_lst;
  }
};
