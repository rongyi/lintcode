// http://www.lintcode.com/zh-cn/problem/maximum-average-subarray
#include <vector>
#include <iostream>
#include <string>
#include <limits>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param nums an array with positive and negative numbers
   * @param k an integer
   * @return the maximum average
   */
  double maxAverage(vector<int>& nums, int k) {
    double l = std::numeric_limits<double>::max();
    double r = std::numeric_limits<double>::min();
    const int n = nums.size();

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] < l) {
        l = nums[i];
      }
      if (nums[i] > r) {
        r = nums[i];
      }
    }

    // double[] sum = new double[n + 1];
    vector<double> sum;
    sum.resize(n + 1);
    sum[0] = 0;
    while (r - l >= 1e-6) {
      double mid = (l + r) / 2.0;

      double min_pre = 0;
      bool check = false;
      for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + nums[i - 1] - mid;
        if (i >= k && sum[i] - min_pre >= 0) {
          check = true;
          break;
        }
        if (i >= k)
          min_pre = std::min(min_pre, sum[i - k + 1]);
      }

      if (check)
        l = mid;
      else
        r = mid;
    }

    return l;
  }
};

int main()
{
  Solution so;
  vector<int> test{5, -10, 4};
  auto ret = so.maxAverage(test, 2);
  cout << ret << endl;
  return 0;
}
