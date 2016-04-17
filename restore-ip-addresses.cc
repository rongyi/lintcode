class Solution {
public:
  /**
   * @param s the IP string
   * @return All possible valid IP addresses
   */
  vector<string> restoreIpAddresses(const string& s) {
    std::vector<std::string> ret;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
          if (i + j + k + 3 >= s.length())
            continue;
          std::string first = s.substr(0, 1 + i);
          std::string second = s.substr(i + 1, 1 + j);
          std::string third = s.substr(i + j + 2, 1 + k);
          std::string fourth = s.substr(k + 1 + i + j + 2);
          // std::cout << first << "." << second << "." << third << "." << fourth << std::endl;
          int firsti = ::atoi(first.c_str());
          int secondi = ::atoi(second.c_str());
          int thirdi = ::atoi(third.c_str());
          int fourthi = ::atoi(fourth.c_str());
          if (first.length() > 1 && first[0] == '0')
            continue;
          if (second.length() > 1 && second[0] == '0')
            continue;
          if (third.length() > 1 && third[0] == '0')
            continue;
          if (fourth.length() > 1 && fourth[0] == '0')
            continue;
          if (firsti >= 0 && firsti <= 255 && secondi >= 0 && secondi <= 255
              && thirdi >= 0 && thirdi <= 255 && fourthi >= 0 && fourthi <= 255) {
            std::stringstream ss;
            ss << first << "."
               << second << "."
               << third << "."
               << fourth;
            ret.push_back(ss.str());
          }
        }
      }
    }
    return ret;
  }
};
