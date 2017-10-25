// http://www.lintcode.com/zh-cn/problem/letter-combinations-of-a-phone-number
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;

class Solution {
public:
  Solution() {
    cellphone_digits_.clear();
    cellphone_digits_.insert(std::make_pair(2, vector<char>{'a', 'b', 'c'}));
    cellphone_digits_.insert(std::make_pair(3, vector<char>{'d', 'e', 'f'}));
    cellphone_digits_.insert(std::make_pair(4, vector<char>{'g', 'h', 'i'}));
    cellphone_digits_.insert(std::make_pair(5, vector<char>{'j', 'k', 'l'}));
    cellphone_digits_.insert(std::make_pair(6, vector<char>{'m', 'n', 'o'}));
    cellphone_digits_.insert(
        std::make_pair(7, vector<char>{'p', 'q', 'r', 's'}));
    cellphone_digits_.insert(std::make_pair(8, vector<char>{'t', 'u', 'v'}));
    cellphone_digits_.insert(
        std::make_pair(9, vector<char>{'w', 'x', 'y', 'z'}));
  }
  /**
   * @param digits A digital string
   * @return all posible letter combinations
   */
  vector<string> letterCombinations(string &digits) {
    vector<string> ret;

    if (digits.empty())
      return ret;
    if (digits.size() == 1) {
      vector<string> empty;
      return reduce(cellphone_digits_[digits[0] - '0'], empty);
    } else if (digits.size() == 2) {
      return map(cellphone_digits_[digits[0] - '0'],
                 cellphone_digits_[digits[1] - '0']);
    } else {
      // lisp name convention
      string cdr = digits.substr(1);
      auto cdr_ret = letterCombinations(cdr);
      return reduce(cellphone_digits_[digits[0] - '0'], cdr_ret);
    }
  }

private:
  vector<string> map(const vector<char> &left, const vector<char> &right) {
    vector<string> ret;
    for (const auto &l : left) {
      string cur;
      cur.push_back(l);
      for (const auto &r : right) {
        cur.push_back(r);
        ret.push_back(cur);
        cur.pop_back();
      }
    }

    return ret;
  }

  vector<string> reduce(const vector<char> &left, vector<string> &acc) {
    vector<string> ret;
    for (const auto &l : left) {
      string cur{""};
      cur.push_back(l);
      if (acc.empty()) {
        ret.push_back(cur);
        cur.pop_back();
      } else {
        for (const auto &s : acc) {
          cur += s;
          ret.push_back(cur);
          cur.clear();
          cur.push_back(l);
        }
      }
    }

    return ret;
  }

private:
  unordered_map<int, vector<char>> cellphone_digits_;
};

int main() {
  Solution so;
  string test("2");
  auto final_test = so.letterCombinations(test);
  for (auto s : final_test)
    cout << s << endl;

  return 0;
}
