// http://www.lintcode.com/zh-cn/problem/system-longest-file-path
#include <algorithm>
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
   * @param input an abstract file system
   * @return return the length of the longest absolute path to file
   */
  int lengthLongestPath(string &input) {
    vector<int> path(input.size() + 2, 0);
    int ret = 0;

    std::vector<string> sections;
    split('\n', input, sections);

    for (auto iter = sections.cbegin(); iter != sections.cend(); iter++) {
      string cur = *iter;
      int depth = std::count(cur.begin(), cur.end(), '\t');
      string strip = cur.substr(cur.find_last_of('\t') + 1);

      if (cur.find('.') != string::npos) {
        int candi = path[depth] + strip.size();
        ret = std::max(ret, candi);
      } else {
        path[depth + 1] = path[depth] + strip.size() + 1;
      }
    }

    return ret;
  }

public:
  /* like python split
  */
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

int main() {
  Solution so;
  string test("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext");
  auto ret = so.lengthLongestPath(test);
  cout << ret << endl;
  return 0;
}
