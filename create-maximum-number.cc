// http://www.lintcode.com/zh-cn/problem/create-maximum-number
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::stack;
using std::max;
using std::min;

class Solution {
public:
  vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
    int m = nums1.size();
    int n = nums2.size();
    vector<int> res(k, 0);

    for (int i = max(0, k - n); i <= min(m, k); i++) {
      auto res1 = findMaxKValue(nums1, i);
      auto res2 = findMaxKValue(nums2, k - i);
      auto temp = merge(res1, res2);
      if (compare(temp, 0, res, 0))
        res = temp;
    }
    return res;
  }

  vector<int> findMaxKValue(vector<int> &nums, int k) {
    vector<int> res;
    if (k == 0)
      return res;
    res = vector<int>(k, 0);
    int j = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      while (j > 0 && n - i + j > k && nums[i] > res[j - 1])
        j--;
      if (j < k)
        res[j++] = nums[i];
    }
    return res;
  }

  vector<int> merge(vector<int> &nums1, vector<int> &nums2) {
    int m = nums1.size();
    int n = nums2.size();
    if (!m)
      return nums2;
    if (!n)
      return nums1;
    vector<int> res(m + n, 0);
    int i = 0, j = 0, k = 0;
    while (i < m || j < n) {
      res[k++] = compare(nums1, i, nums2, j) ? nums1[i++] : nums2[j++];
    }
    return res;
  }

  bool compare(vector<int> &res1, int i, vector<int> &res2, int j) {
    while (i < res1.size() && j < res2.size() && res1[i] == res2[j]) {
      i++;
      j++;
    }
    return j == res2.size() || (i < res1.size() && res1[i] > res2[j]);
  }
};

int main() {
  Solution so;
  vector<int> nums1{3, 4, 6, 5};
  vector<int> nums2{9, 1, 2, 5, 8, 3};
  auto ret = so.maxNumber(nums1, nums2, 5);
  return 0;
}
