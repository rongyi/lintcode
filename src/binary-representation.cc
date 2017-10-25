// http://www.lintcode.com/zh-cn/problem/binary-representation
#include <algorithm>
#include <iostream>
#include <sstream>
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
  /**
   *@param n: Given a decimal number that is passed in as a string
   *@return: A string
   */
  string binaryRepresentation(string n) {
    std::stringstream ss;

    string interger_part;
    string decimal_part;
    if (n.find_first_of('.', 0) == std::string::npos) {
      interger_part = n;
    } else {
      interger_part = n.substr(0, n.find_first_of('.'));
      decimal_part = n.substr(n.find_first_of('.') + 1);
    }
    // cout << interger_part << endl;
    // cout << decimal_part << endl;

    // integer part
    string binary_int;
    int i = std::stoi(interger_part);
    bool is_negtive = i < 0;

    if (i == std::numeric_limits<int>::min()) {
      for (unsigned j = 0; j < sizeof(int); j++) {
        ss << "1";
      }
    } else if (i == 0) {
      binary_int = "0";
    } else {
      i = std::abs(i);
      while (i != 0) {
        ss << (i & 0x1);
        i >>= 1;
      }
      binary_int = ss.str();
      // for decimal part
      ss.clear();

      std::reverse(binary_int.begin(), binary_int.end());
    }

    // integer part done

    unordered_set<double> decimal_set;
    string binary_dec;
    if (decimal_part != "" && std::stoll(decimal_part) != 0) {
      double d = std::stod("0." + decimal_part);

      while (d > 0) {
        if (binary_dec.size() > 32 ||
            decimal_set.find(d) != decimal_set.end()) {
          return "ERROR";
        }
        decimal_set.insert(d);
        d *= 2;
        if (d >= 1) {
          binary_dec += "1";
          d -= 1;
        } else {
          binary_dec += "0";
        }
      }
    }

    string ret;
    if (binary_dec != "") {
      ret = binary_int + "." + binary_dec;
    } else {
      ret = binary_int;
    }
    if (is_negtive) {
      ret.insert(0, "-");
    }

    return ret;
  }
};

int main() {
  Solution so;
  auto ret = so.binaryRepresentation("28187281.128121212121");
  cout << ret << endl;
  return 0;
}
