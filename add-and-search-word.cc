// http://www.lintcode.com/zh-cn/problem/add-and-search-word
#include <vector>
#include <iostream>
#include <cstring>
#include <string>
#include <cctype>

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
    if (word.empty())
      return;

    TrieNode *p = root;
    for (auto c : word) {
      if (!p->node_[std::tolower(c) - 'a'])
        p->node_[std::tolower(c) - 'a'] = new TrieNode();
      p = p->node_[std::tolower(c) - 'a'];
    }
    p->is_leaf_ = true;
  }

  // Returns if the word is in the data structure. A word could
  // contain the dot character '.' to represent any one letter.
  bool search(string word) {
    if (word.empty())
      return false;

    return search(word, root, 0);
  }

  bool search(string word, TrieNode *root, unsigned level) {
    if (level == word.size())
      return root->is_leaf_;
    const char cur = std::tolower(word[level]);
    if (cur == '.') {
      for (auto c : root->node_) {
        if (c && search(word, c, level + 1))
          return true;
      }
      return false;
    } else {
      return root->node_[cur - 'a'] && search(word, root->node_[cur - 'a'], level + 1);
    }
  }

  WordDictionary() {
    root = new TrieNode();
  }

  void do_delete(TrieNode *root) {
    if (!root)
      return;
    for (auto p : root->node_) {
      if (p) {
        do_delete(p);
        p = nullptr;
      }
    }

    if (root->HasNoChild()) {
      delete root;
      root = nullptr;
    }
  }

  ~WordDictionary() {
    do_delete(root);
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
  WordDictionary wd;
  wd.addWord("rongyi");
  auto ret = wd.search("r....i");
  cout << ret << endl;
  return 0;
}
