// http://www.lintcode.com/zh-cn/problem/decode-ways
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param s a string,  encoded message
   * @return an integer, the number of ways decoding
   */
  int numDecodings(string& s) {
    if(s.empty() || s[0]<'1' || s[0]>'9') return 0;
    vector<int> dp(s.size()+1,0);
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 1; i < s.size(); i++) {
      if(!isdigit(s[i]))
        return 0;
      int v = (s[i - 1] - '0') * 10 + (s[i] - '0');
      /*
        XY可以解码的条件是：9<XY<=26
        Y可以单独解码的条件是：Y != '0'*/
      if(v <= 26 && v > 9)
        dp[i + 1] += dp[i - 1];
      if(s[i] != '0')
        dp[i + 1] += dp[i];
      if(dp[i + 1] == 0)
        return 0;
    }
    return dp[s.size()];
  }
};

int main()
{
  Solution so;
  std::string test("192611");
  auto ret = so.numDecodings(test);
  cout << ret << endl;
  return 0;
}
