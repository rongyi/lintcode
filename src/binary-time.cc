// http://www.lintcode.com/zh-cn/problem/binary-time
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /*
  * @param : the number of "1"s on a given timetable
  * @return: all possible time
  * from example we can see 4 bits for hour and 6 bits for hour, and this
  * is a combination problem.
  */
  vector<string> binaryTime(int num) {
    auto hnums = genVector(4);
    auto mnums = genVector(6);
    if (num == 0) {
      auto hvec = mkHour(0, hnums);
      auto mvec = mkMinute(0, mnums);
      return multiply(hvec, mvec);
    }
    vector<string> ret;

    for (int i = 0; i <= num; i++) {
      // count of "1" in minutes part
      int j = num - i;

      // first
      auto hvec = mkHour(i, hnums);
      auto mvec = mkMinute(j, mnums);
      auto tmp = multiply(hvec, mvec);
      for (auto &s : tmp) {
        ret.push_back(s);
      }
    }

    return ret;
  }

  vector<string> mkHour(int n, const vector<int> &nums) {
    vector<string> ret;
    if (n == 0) {
      ret.push_back("0");
      return ret;
    }

    vector<int> c(nums.size(), 0);

    vector<vector<int>> comb;
    combine(nums, c, 0, n, comb);
    for (auto c : comb) {
      auto i = reduce(c);
      if (i >= 12) {
        continue;
      }
      ret.push_back(std::to_string(i));
    }

    return ret;
  }

  vector<string> mkMinute(int n, const vector<int> &nums) {
    vector<string> ret;
    if (n == 0) {
      ret.push_back("00");
      return ret;
    }

    vector<int> c(nums.size(), 0);

    vector<vector<int>> comb;
    combine(nums, c, 0, n, comb);
    for (auto c : comb) {
      auto i = reduce(c);
      if (i > 59) {
        continue;
      }
      if (i < 10) {
        ret.push_back("0" + std::to_string(i));
      } else {
        ret.push_back(std::to_string(i));
      }
    }

    return ret;
  }

  vector<string> multiply(const vector<string> &hvec,
                          const vector<string> &mvec) {
    vector<string> ret;
    for (auto h : hvec) {
      for (auto m : mvec) {
        auto time = h + ":" + m;
        ret.push_back(time);
      }
    }
    return ret;
  }

  void combine(const vector<int> &n, vector<int> &choose, int index, int k,
               vector<vector<int>> &ret) {
    static int count = 0;
    if (count == k) {
      vector<int> tmp;
      for (int i = 0; i < n.size(); i++) {
        if (choose[i] == 1) {
          tmp.push_back(n[i]);
        }
      }
      ret.push_back(tmp);
    } else if ((n.size() - index) >= (k - count)) {
      choose[index] = 1;
      count++;
      combine(n, choose, index + 1, k, ret);

      choose[index] = 0;
      count--;
      combine(n, choose, index + 1, k, ret);
    }
  }

  int reduce(const vector<int> &combine) {
    int ret = 0;
    for (auto c : combine) {
      ret |= c;
    }
    return ret;
  }

  // generate a vector of size n
  vector<int> genVector(int n) {
    vector<int> ret;

    for (int i = 0; i <= n; i++) {
      ret.push_back(1 << i);
    }

    return ret;
  }
};

int main() {
  Solution so;

  // vector<int> n{1, 2, 4, 8};
  // vector<int> c(n.size(), 0);
  // vector<vector<int>> ret;

  // so.combine(n, c, 0, 2, ret);

  // cout << ret.size() << endl;
  // for (auto c : ret) {
  //   cout << so.reduce(c) << endl;
  // }

  auto v = so.binaryTime(1);
  for (auto s : v) {
    cout << s << " ";
  }
  cout << endl;

  return 0;
}
