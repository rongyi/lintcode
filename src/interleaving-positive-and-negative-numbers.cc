// http://www.lintcode.com/zh-cn/problem/interleaving-positive-and-negative-numbers
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
  /**
   * @param A: An integer array.
   * @return: void
   */
  void rerange(vector<int> &A) {
    std::vector<int> postive;
    std::vector<int> negtive;
    for (auto i : A) {
      if (i > 0)
        postive.push_back(i);
      else
        negtive.push_back(i);
    }

    int i = 0;
    for (int pi = 0, ni = 0; i < A.size(); i++) {
      if (postive.size() > negtive.size()) {
        if (i % 2 == 0)
          A[i] = postive[pi++];
        else
          A[i] = negtive[ni++];
      } else {
        if (i % 2 == 0)
          A[i] = negtive[ni++];
        else
          A[i] = postive[pi++];
      }
    }
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  vector<int> test{28, 2,  -22, -27, 2, 9,  -33, -4, -18, 26,
                   25, 34, -35, -17, 2, -2, 32,  35, -8};
  so.rerange(test);
  return 0;
}
