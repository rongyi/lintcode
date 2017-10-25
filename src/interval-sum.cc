// http://www.lintcode.com/zh-cn/problem/interval-sum
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */

class Interval {
public:
  int start, end;
  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class Solution {
public:
  /**
   *@param A, queries: Given an integer array and an query list
   *@return: The result list
   */
  vector<long long> intervalSum(vector<int> &a, vector<Interval> &queries) {
    vector<long long> ret;
    if (a.empty())
      return ret;
    const int n = a.size();
    vector<long long> prefix_sum(n + 1, 0);
    for (int i = 1; i < n + 1; i++) {
      prefix_sum[i] = prefix_sum[i - 1] + a[i - 1];
    }

    for (auto q : queries) {
      int start = q.start;
      int end = q.end;
      long long cur_ret = prefix_sum[end + 1] - prefix_sum[start];
      ret.push_back(cur_ret);
    }

    return ret;
  }
};
