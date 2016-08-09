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
  Solution() {
    for (int i = 0; i < 26; i++) {
      secret_book_[i + 1] = 'A' + i;
    }
  }
  /**
   * @param s a string,  encoded message
   * @return an integer, the number of ways decoding
   */
  int numDecodings(string& s) {
    vector<string> ret;

    string cur;
    bool is_invalid = false;
    do_decode(s, ret, cur, is_invalid);


    return is_invalid ? 0 : ret.size();
  }

  void do_decode(string &s, vector<string> &ret, string &cur, bool &is_invalid) {
    if (is_invalid)
      return;
    if (s.empty()) {
      if (!cur.empty())
        ret.push_back(cur);
      return;
    }

    // 10 is a unit, can not decoded as 1 and 0
    if (s.size() >= 2 && s.at(1) == '0') {
      char c = secret_book_[std::stoi(s.substr(0, 2))];
      cur += c;
      std::string n = s.substr(2);
      do_decode(n, ret, cur, is_invalid);
      return;
    }

    int i = s.at(0) - '0';
    // encount invalid sequence
    if (i > 26 || i <= 0) {
      is_invalid = true;
      return;
    }

    char c = secret_book_[s.at(0) - '0'];
    cur += c;
    std::string n = s.substr(1);
    do_decode(n, ret, cur, is_invalid);

    if (s.size() >= 2) {
      int i = (s.at(0) - '0') * 10 + (s.at(1) - '0');
      // the last two will change to one
      if (i >= 1 && i <= 26) {
        cur.pop_back();
        cur.pop_back();
        char c = secret_book_[i];
        cur += c;
        std::string n = s.substr(2);
        do_decode(n, ret, cur, is_invalid);
      }
    }
  }

private:
  std::unordered_map<int, char> secret_book_;
};

int main()
{
  Solution so;
  std::string test("192611");
  auto ret = so.numDecodings(test);
  cout << ret << endl;
  return 0;
}
