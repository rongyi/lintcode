#include <bitset>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::unordered_set;

class Solution {
public:
  /*
  * @param : a given string
  * @param : another given string
  * @return: An array of missing string
  */
  vector<string> missingString(string str1, string str2) {
    vector<string> v1;
    vector<string> v2;
    split(' ', str1, v1);
    split(' ', str2, v2);
    unordered_set<string> set2;
    for (auto &s : v2)
      set2.insert(s);
    vector<string> ret;
    for (auto &s : v1) {
      if (set2.find(s) == set2.end()) {
        ret.emplace_back(s);
      }
    }
    return ret;
  }

  inline void split(const char delim, const std::string &input,
                    std::vector<std::string> &output) {
    if (input.empty())
      return;

    output.clear();
    size_t token_start_pos = 0;
    size_t token_size = 0;

    for (size_t i = 0; i <= input.size() - 1; ++i) {
      if (input[i] == delim) {
        if (token_size > 0) {
          output.push_back(std::string(input, token_start_pos, token_size));
        }
        token_start_pos = i + 1;
        token_size = 0;
      } else {
        ++token_size;
      }
    }

    // the last one
    token_size = input.size() - token_start_pos;
    if (token_size > 0) {
      output.push_back(std::string(input, token_start_pos, token_size));
    }
  }
};
