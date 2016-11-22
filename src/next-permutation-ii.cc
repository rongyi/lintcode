// http://www.lintcode.com/zh-cn/problem/next-permutation-ii
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
   * @param nums: a vector of integers
   * @return: return nothing (void), do not return anything, modify nums in-place instead
   1. 从低位向高位（从右向左）找第一个递减的数：s[i]<s[i+1]。如果不存在，则表明该permutation已经最大，next permutation为当前序列的逆序。
   2. 在s[i+1:n-1]中找一个j，使s[j]>s[i]>=s[j+1]，swap(s[i], s[j])
   3. 将s[i+1:n-1]排序，从低位到高位单调递减。
  */
  void nextPermutation(vector<int> &nums) {
    int j = -1;
    int k = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
      if (nums[i] < nums[i + 1])
        j = i;
    }

    if (j >= 0) {
      for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] > nums[j]) {
          k = i;
        }
      }
      std::swap(nums[j], nums[k]);
    }

    std::reverse(nums.begin() + j + 1, nums.end());
  }
};
