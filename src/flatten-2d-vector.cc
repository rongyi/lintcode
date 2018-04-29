// http://www.lintcode.com/zh-cn/problem/flatten-2d-vector
#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Vector2D {
public:
  Vector2D(vector<vector<int>>& vec2d) : current_(0){
    for (unsigned i = 0; i < vec2d.size(); ++i) {
      for (unsigned j = 0; j < vec2d[i].size(); ++j) {
        flat_.push_back(vec2d[i][j]);
        count_++;
      }
    }
  }

  int next() {
    return flat_[current_++];
  }

  bool hasNext() {
    return current_ < count_;
  }

private:
  vector<int> flat_;
  unsigned count_;
  unsigned current_;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
