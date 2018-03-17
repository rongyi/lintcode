class Solution {
public:
  /**
   * @param character: a character
   * @return: a character
   */
  char lowercaseToUppercase(char character) {
    return character - 'a' + 'A';
  }
};
