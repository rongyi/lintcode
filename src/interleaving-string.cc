// http://www.lintcode.com/zh-cn/problem/interleaving-string
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * Determine whether s3 is formed by interleaving of s1 and s2.
   * @param s1, s2, s3: As description.
   * @return: true of false.
   */
  bool isInterleave(string s1, string s2, string s3) {
    if (s1.empty() && s2.empty() && s3.empty())
      return true;
    if (s1.empty())
      return s2 == s3;
    if (s2.empty())
      return s1 == s3;
    const int len1 = s1.size();
    const int len2 = s2.size();

    if (len1 + len2 != s3.size())
      return false;

    // 设状态f[i][j]，表示s1[0,i]和s2[0,j]，匹配s3[0,
    // i+j]。如果s1的最后一个字符等于s3的最后一个字符，则f[i][j]=f[i-1][j]；
    // 如果s2的最后一个字符等于s3的最后一个字符，则f[i][j]=f[i][j-1]
    vector<vector<bool>> ret(len1 + 1, vector<bool>(len2 + 1, false));

    ret[0][0] = true;

    for (int i = 1; i <= len1; i++) {
      if (s1[i - 1] == s3[i - 1])
        ret[i][0] = true;
    }

    for (int j = 1; j <= len2; j++) {
      if (s2[j - 1] == s3[j - 1])
        ret[0][j] = true;
    }

    for (int i = 1; i <= len1; i++) {
      for (int j = 1; j <= len2; j++) {
        ret[i][j] = (ret[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
                    (ret[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
      }
    }

    return ret[len1][len2];
  }
};

int main() {
  Solution so;
  auto ret = so.isInterleave("abbcddef", "accbbbcd", "abbcddefaccbbbdc");

  cout << ret << endl;
  return 0;
}
