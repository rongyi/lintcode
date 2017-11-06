// http://www.lintcode.com/zh-cn/problem/the-number-in-words
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  const static std::vector<string> kLittle;
  const static std::vector<string> kBig;
  const static std::vector<string> kSections;
  /*
  * @param : the number
  * @return: the number in words
  */
  string convertWords(int number) {
    string ret = section(number % 1000);
    for (int i = 0; i < 3; i++) {
      number /= 1000;
      ret = number % 1000
                ? section(number % 1000) + " " + kSections[i] + " " + ret
                : ret;
    }
    while (ret.back() == ' ') {
      ret.pop_back();
    }
    return ret.empty() ? "zero" : ret;
  }

private:
  string section(int num) {
    string ret;
    int a = num / 100;
    int b = num % 100;
    int c = num % 10;
    ret = b < 20 ? kLittle[b] : kBig[b / 10] + (c ? " " + kLittle[c] : "");
    if (a > 0) {
      ret = kLittle[a] + " hundred" + (b ? " " + ret : "");
    }
    return ret;
  }
};

const std::vector<string> Solution::kLittle = {
    "",        "one",     "two",       "three",    "four",
    "five",    "six",     "seven",     "eight",    "nine",
    "ten",     "eleven",  "twelve",    "thirteen", "fourteen",
    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
const std::vector<string> Solution::kBig = {
    "",      "",      "twenty",  "thirty", "forty",
    "fifty", "sixty", "seventy", "eighty", "ninety"};
const std::vector<string> Solution::kSections = {"thousand", "million",
                                                 "billion"};
