// http://www.lintcode.com/zh-cn/problem/permutation-index-ii
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param A an integer array
   * @return a long integer
   */
  long long permutationIndexII(vector<int> &nums) {
    if (nums.empty())
      return 0;

    const int m = nums.size();
    long long ret = 1;
    long long factor = 1;
    for (int i = m - 1; i >= 0; --i) {
      int rank = 0;
      std::unordered_map<int, int> dup_count;
      ++dup_count[nums[i]];
      for (int j = i + 1; j < m; ++j) {
        ++dup_count[nums[j]];
        // previous number
        if (nums[j] < nums[i])
          ++rank;
      }

      ret += rank * factor / duplicate(dup_count);
      factor *= (nums.size() - i);
    }

    return ret;
  }

private:
  long long duplicate(const std::unordered_map<int, int> &dup_count) {
    if (dup_count.empty())
      return 1;
    long long ret = 1;
    for (auto it = dup_count.cbegin(); it != dup_count.end(); ++it) {
      ret *= fact(it->second);
    }
    return ret;
  }
  long long fact(int num) {
    long long ret = 1;
    for (int i = 1; i <= num; i++) {
      ret *= i;
    }
    return ret;
  }
};
