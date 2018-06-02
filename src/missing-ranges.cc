// http://www.lintcode.com/zh-cn/problem/missing-ranges
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Solution {
public:
  /*
   * @param nums: a sorted integer array
   * @param lower: An integer
   * @param upper: An integer
   * @return: a list of its missing ranges
   */
  vector<string> findMissingRanges(vector<int> &nums, int lower, int upper) {
    vector<string> ret;
    auto origin_lower = lower;

    for (int i = 0; i < nums.size(); ++i) {
      auto current = nums[i];
      auto gap = tostring(lower, current, i);
      if (gap != "") {
        ret.push_back(gap);
      }
      lower = current;
    }

    if (nums.empty()) {
      if (lower == upper) {
        ret.push_back(std::to_string(lower));
        return ret;
      }
      // else the all range
      ret.push_back(std::to_string(lower) + "->" + std::to_string(upper));
      return ret;
    }
    // the last case
    if (lower != upper) {
      if (lower + 1 == upper) {
        ret.push_back(std::to_string(lower + 1));
      } else {
        ret.push_back(std::to_string(lower + 1) + "->" + std::to_string(upper));
      }
    }
    return ret;
  }

private:
  string tostring(int64_t start, int64_t end, int64_t i) {
    if (i == 0) {
      if (start + 1 == end) {
        return std::to_string(start);
      } else if (start < end) {
        return std::to_string(start) + "->" + std::to_string(end - 1);
      }
    }

    if (end - start < 2) {
      return "";
    } else if (end - start == 2) {
      return std::to_string(start + 1);
    }
    if (i == 0) {
      return std::to_string(start) + "->" + std::to_string(end - 1);
    }
    return std::to_string(start + 1) + "->" + std::to_string(end - 1);
  }
};

int main() {
  vector<int> input{0, 1, 3, 50, 75};
  Solution so;
  auto ret = so.findMissingRanges(input, 0, 99);
  for (auto s : ret) {
    cout << s << " ";
  }
  cout << endl;
}
