// http://www.lintcode.com/zh-cn/problem/restore-ip-addresses/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param s the IP string
   * @return All possible valid IP addresses
   * a brute force solution
   */
  vector<string> restoreIpAddressesLame(const string &s) {
    std::vector<std::string> ret;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
          if (i + j + k + 3 >= s.length())
            continue;
          std::string first = s.substr(0, 1 + i);
          std::string second = s.substr(i + 1, 1 + j);
          std::string third = s.substr(i + j + 2, 1 + k);
          std::string fourth = s.substr(k + 1 + i + j + 2);
          // std::cout << first << "." << second << "." << third << "." <<
          // fourth << std::endl;
          int firsti = ::atoi(first.c_str());
          int secondi = ::atoi(second.c_str());
          int thirdi = ::atoi(third.c_str());
          int fourthi = ::atoi(fourth.c_str());
          if (first.length() > 1 && first[0] == '0')
            continue;
          if (second.length() > 1 && second[0] == '0')
            continue;
          if (third.length() > 1 && third[0] == '0')
            continue;
          if (fourth.length() > 1 && fourth[0] == '0')
            continue;
          if (firsti >= 0 && firsti <= 255 && secondi >= 0 && secondi <= 255 &&
              thirdi >= 0 && thirdi <= 255 && fourthi >= 0 && fourthi <= 255) {
            std::stringstream ss;
            ss << first << "." << second << "." << third << "." << fourth;
            ret.push_back(ss.str());
          }
        }
      }
    }
    return ret;
  }

  // using dfs to solve this problem
  vector<string> restoreIpAddresses(string &s) {
    vector<string> ret;
    vector<string> ip;
    dfs(s, ip, ret, 0);
    return ret;
  }

private:
  void dfs(string &s, vector<string> &ip, vector<string> &ret, int start) {
    if (ip.size() == 4 && start == s.length()) {
      ret.push_back(ip[0] + "." + ip[1] + "." + ip[2] + "." + ip[3]);
      return;
    }
    // 剩余太多
    if (s.length() - start > (4 - ip.size()) * 3)
      return;
    // 剩余太少
    // IP地址点分的每一位最多3个字符，太长了
    if (s.length() - start > (4 - ip.size()) * 3)
      return;
    // IP地址点分的每一位最小一个字符，太短了
    if (s.length() - start < (4 - ip.size()))
      return;
    int num = 0;
    for (int i = start; i < start + 3 && i < s.length(); ++i) {
      num = num * 10 + (s[i] - '0');
      if (num < 0 || num > 255)
        continue;
      ip.push_back(s.substr(start, i - start + 1));
      dfs(s, ip, ret, i + 1);
      ip.pop_back();
      // 遇到一个不合法的情况，这里就没必要再走下去, break后继续弹临时存储ip
      // "00255255"这种case，遇到0不再继续往前续
      if (num == 0) {
        break;
      }
    }
  }
};

int main() {
  Solution so;
  string test{"00255255"};
  auto ret = so.restoreIpAddresses(test);
  for (auto &s : ret) {
    cout << s << endl;
  }
  return 0;
}
