// http://www.lintcode.com/zh-cn/problem/first-position-of-target
#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param nums: The integer array.
   * @param target: Target number to find.
   * @return: The first position of target. Position starts from 0.
   */
  int binarySearch(vector<int> &array, int target) {
    if (array.empty())
      return -1;
    int start = 0;
    int end = array.size() - 1;
    while (start <= end) {
      const int mid = start + (end - start) / 2;
      if (array[mid] < target) {
        start = mid + 1;
      } else if (array[mid] > target){
        end = mid - 1;
      } else {
        int j = mid;
        for (; j >=0 && array[j] == array[mid]; --j) {
          ;
        }
        return j + 1;
      }
    }
    return -1;
  }
};

int main()
{
  vector<int> test{3,4,5,8,8,8,8,10,13,14};
  Solution so;
  auto ret = so.binarySearch(test, 8);
  cout << ret << endl;
  return 0;
}
