#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:

  Solution() : ret_(-1) {}
  /**
   * @param n an integer
   * @param str a string with number from 1-n in
   *            random order and miss one number
   * @return an integer
   */
  int findMissing2(int n, string& str) {
    vector<bool> visited(n + 1, false);
    dfs(n, str, 0, visited);

    return ret_;
  }

  void dfs(int n, const string &s, int index, vector<bool> &visited) {
    // return case
    if (index >= s.size()) {
      vector<int> ret;
      for (int i = 1; i <= n; i++) {
        if (!visited[i])
          ret.push_back(i);
      }
      if (ret.size() == 1)
        ret_ = ret[0];

      return;
    }
    if (s[index] == '0') {
      return;
    }
    for (int i = 1; i < 3; i++) {
      int num = atoi(s, index, i);
      if (num >= 1 && num <= n && !visited[num]) {
        visited[num] = true;
        dfs(n, s, index + i, visited);
        visited[num] = false;
      }
    }
  }
private:
  int atoi(const string &s, int start, int len) {
    return ::atoi(s.substr(start, len).c_str());
  }

private:
  int ret_;
};

int main()
{
  Solution so;
  string input("12131415161819201234568910117");
  auto i = so.findMissing2(20, input);
  cout << i << endl;
  return 0;
}
