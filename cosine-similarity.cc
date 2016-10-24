// http://www.lintcode.com/zh-cn/problem/cosine-similarity
#include <vector>
#include <iostream>
#include <string>
#include <cmath>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param A: An integer array.
   * @param B: An integer array.
   * @return: Cosine similarity.
   */
  double cosineSimilarity(vector<int> a, vector<int> b) {
    if (a.size() != b.size())
      return 2.0;
    double ab = 0;
    double aa = 0;
    double bb = 0;
    for (int i = 0; i < a.size(); i++) {
      aa += a[i] * a[i];
      bb += b[i] * b[i];
      ab += a[i] * b[i];
    }
    if (aa == 0 || bb == 0)
      return 2.0;

    return ab / ::sqrt(aa) / ::sqrt(bb);
  }
};
