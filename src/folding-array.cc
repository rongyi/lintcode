// http://www.lintcode.com/zh-cn/problem/folding-array
#include <bitset>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /*
  * @param : the original array
  * @param : the direction each time
  * @return: the final folded array
  */
  vector<int> folding(vector<int> &nums, vector<int> &req) {
    // write your code here

    for (int i = 0; i < req.size(); i++)
      if (req[i] == 0)
        left(nums, 1 << i);
      else
        right(nums, 1 << i);

    return nums;
  }
  void left(vector<int> &nums, int index) {
    //左折叠，右不变、下移,左翻转、位于头部
    int cnt = nums.size() / (index * 2);
    vector<int> out;
    for (int i = 0; i < index; i++) {
      //迭代器末尾的位置，等于开头的+cnt；
      vector<int> temp1(nums.begin() + i * cnt * 2,
                        nums.begin() + i * cnt * 2 + cnt);
      vector<int> temp2(nums.begin() + i * cnt * 2 + cnt,
                        nums.begin() + i * cnt * 2 + cnt + cnt);

      std::reverse(temp1.begin(), temp1.end());

      out.insert(out.begin(), temp1.begin(), temp1.end());
      out.insert(out.end(), temp2.begin(), temp2.end());
    }
    nums = out;
    return;
  }
  void right(vector<int> &nums, int index) {
    //右折叠，左不变、下移，右翻转，位于头部
    int cnt = nums.size() / (index * 2);
    vector<int> out;
    for (int i = 0; i < index; i++) {
      vector<int> temp1(nums.begin() + i * cnt * 2,
                        nums.begin() + i * cnt * 2 + cnt);
      vector<int> temp2(nums.begin() + i * cnt * 2 + cnt,
                        nums.begin() + i * cnt * 2 + cnt + cnt);

      reverse(temp2.begin(), temp2.end());

      out.insert(out.begin(), temp2.begin(), temp2.end());
      out.insert(out.end(), temp1.begin(), temp1.end());
    }
    nums = out;
    return;
  }
};
