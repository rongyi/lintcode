// http://www.lintcode.com/zh-cn/problem/hash-function
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
   * @param key: A String you should hash
   * @param HASH_SIZE: An integer
   * @return an integer
   */
  int hashCode(string key,int HASH_SIZE) {
    if (key.empty())
      return 0;
    const int len = key.size();
    long long ret = 0;
    for (int i = 0; i < len; i++) {
      ret = ret * 33 + (int)key[i];
      ret %= HASH_SIZE;
    }
    return ret;
  }
};

int main(int argc, char *argv[])
{
  Solution so;
  auto ret = so.hashCode("abcd", 1000);
  cout << ret << endl;
  return 0;
}
