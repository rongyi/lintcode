// http://www.lintcode.com/zh-cn/problem/number-of-airplanes-in-the-sky
#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

class Interval {
public:
  int start, end;
  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class Solution {
public:
  /**
   * @param intervals: An interval array
   * @return: Count of airplanes are in the sky.
   */
  int countOfAirplanes(vector<Interval> &airplanes) {
    if (!airplanes.size())
      return 0;
    std::vector<int> departure;
    std::vector<int> arrive;

    for (auto &a : airplanes) {
      departure.push_back(a.start);
      arrive.push_back(a.end);
    }
    std::sort(departure.begin(), departure.end());
    std::sort(arrive.begin(), arrive.end());
    int ret = 0;

    for (int i = 0, di = 0, ai = 0, count = 0;; i++) {
      // 如果多架飞机降落和起飞在同一时刻，我们认为降落有优先权。
      if (i >= arrive[ai] && ai < arrive.size()) {
        while (ai < arrive.size() && arrive[ai] == i) {
          if (count > 0)
            count--;
          ai++;
        }
      }

      if (i >= departure[di] && di < departure.size()) {
        while (di < departure.size() && departure[di] == i) {
          count++;
          di++;
        }
      }

      ret = std::max(ret, count);
      if (ai >= arrive.size() && di >= departure.size())
        break;
    }
    return ret;
  }
};

int main(int argc, char *argv[]) {
  vector<Interval> test;
  test.push_back(Interval(3, 11));
  test.push_back(Interval(3, 11));
  test.push_back(Interval(3, 11));
  // test.push_back(Interval(5, 8));
  Solution so;
  auto ret = so.countOfAirplanes(test);
  std::cout << ret << std::endl;
  return 0;
}
