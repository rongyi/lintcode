// http://www.lintcode.com/zh-cn/problem/assignment-operator-overloading-c-only

#include <cstring>
class Solution {
public:
  char *m_pData;
  Solution() { this->m_pData = nullptr; }
  Solution(char *pData) { this->m_pData = pData; }

  // Implement an assignment operator
  Solution operator=(const Solution &other) {
    if (this != &other) {
      char *new_char = nullptr;
      if (other.m_pData) {
        new_char = new char[ ::strlen(other.m_pData) + 1];
        ::strcpy(new_char, other.m_pData);
      }

      if (m_pData) {
        delete[] m_pData;
      }
      m_pData = new_char;
    }
    return *this;
  }
};
