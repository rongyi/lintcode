// http://www.lintcode.com/zh-cn/problem/simplify-path/

class Solution {
public:
  /**
   * @param path the original path
   * @return the simplified path
   */
  string simplifyPath(string& path) {
    // Write your code here
    vector<string> dir_lst;
    for (auto i = path.begin(); i != path.end();) {
      i++;

      auto j = std::find(i, path.end(), '/');
      auto dir = string(i, j);

      if (!dir.empty() && dir != ".") {
        if (dir == "..") {
          if (!dir_lst.empty())
            dir_lst.pop_back();
        } else {
          dir_lst.push_back(dir);
        }

      }

      i = j;
    }
    std::stringstream ss;
    if (dir_lst.empty()) {
      ss << "/";
    } else {
      for (auto dir : dir_lst)
        ss << "/" << dir;
    }
    return ss.str();

  }
};
