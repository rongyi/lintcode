// http://www.lintcode.com/zh-cn/problem/add-and-search-word
#include <vector>
#include <iostream>
#include <cstring>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

struct TrieNode {
  static const int NUM = 26;
  TrieNode () : is_leaf_(false){
    std::memset(node_, 0, sizeof(node_));
  }

  bool HasNoChild() const {
    for (auto p : node_) {
      if (p)
        return false;
    }
    return true;
  }

  bool is_leaf_;
  TrieNode *node_[NUM];
};

class WordDictionary {
public:
  // Adds a word into the data structure.
  void addWord(string word) {

  }

  // Returns if the word is in the data structure. A word could
  // contain the dot character '.' to represent any one letter.
  bool search(string word) {

  }
  WordDictionary() {
    root = new TrieNode();
  }
  ~WordDictionary() {

  }

private:
  TrieNode *root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

int main()
{
  TrieNode node;
  auto nochild = node.HasNoChild();
  cout << nochild << endl;
  return 0;
}
