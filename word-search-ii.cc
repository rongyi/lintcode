// http://www.lintcode.com/zh-cn/problem/word-search-ii
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <unordered_set>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::unordered_set;

// from file: ./implement-trie.cc
namespace detail {
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

class Trie {
public:
  Trie() {
    root = new TrieNode();
  }

  // Inserts a word into the trie.
  void insert(string word) {
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

  // Returns if the word is in the trie.
  bool search(string word) {
    if (word.empty())
      return false;
    return search(word, root, 0);
  }

  // Returns if there is any word in the trie
  // that starts with the given prefix.
  bool startsWith(string prefix) {
    if (prefix.empty())
      return false;
    return start(prefix, root, 0);
  }

  bool search(const string &word, TrieNode *root, unsigned level) {
    if (level == word.size())
      return root->is_leaf_;
    const char cur = std::tolower(word[level]);
    return root->node_[cur - 'a'] && search(word, root->node_[cur - 'a'], level + 1);
  }
  bool start(const string &word, TrieNode *root, unsigned level) {
    if (level == word.size())
      return root != nullptr;
    const char cur = std::tolower(word[level]);
    return root->node_[cur - 'a'] && start(word, root->node_[cur - 'a'], level + 1);
  }

  ~Trie() {
    do_delete(root);
  }

private:
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
  TrieNode* root;
};
} // namespace detail

class Solution {
public:
  /**
   * @param board: A list of lists of character
   * @param words: A list of string
   * @return: A list of string
   */
  vector<string> wordSearchII(vector<vector<char> > &board,
                              vector<string> &words) {
    vector<string> ret;
    if (board.empty() || board[0].empty() || words.empty())
      return ret;

    const int m = board.size();
    const int n = board[0].size();

    // uniq ret
    unordered_set<string> uret;

    for (auto &w : words) {
      trie_.insert(w);
    }

    // the A.I part
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    string s;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        s.push_back(board[i][j]);
        if (trie_.search(s))
          uret.insert(s);
        if (trie_.startsWith(s))
          search(s, board, i, j, visited, uret);
        s.pop_back();
      }
    }
    for (auto & w : uret)
      ret.push_back(w);
    return ret;
  }


  void search(string &word,
              const vector<vector<char>> &board,
              int i, int j,
              vector<vector<bool>> &visited,
              unordered_set<string> &uret) {

    auto isBoundaryValid = [](int cur_row, int cur_col, int row_size, int col_size, vector<vector<bool>> &visited) {
      if (cur_row < 0 || cur_col < 0 ||
          cur_row == row_size || cur_col == col_size ||
          visited[cur_row][cur_col] == true) {
        return false;
      }
      return true;
    };
    // indicate four direction
    const static int dx[4]{1, 0, -1, 0};
    const static int dy[4]{0, 1, 0, -1};

    // mark as visited
    visited[i][j] = true;

    int next_x;
    int next_y;
    for (int cur_dicrection = 0; cur_dicrection < 4; cur_dicrection++) {
      next_x = i + dx[cur_dicrection];
      next_y = j + dy[cur_dicrection];
      if (isBoundaryValid(next_x, next_y, board.size(), board[0].size(), visited)) {
        word.push_back(board[next_x][next_y]);
        if (trie_.search(word))
          uret.insert(word);
        if (trie_.startsWith(word))
          search(word, board, next_x, next_y, visited, uret);
        word.pop_back();
      }
    }

    // mark it back
    visited[i][j] = false;
  }

private:
  detail::Trie trie_;
};

int main()
{
  Solution so;
  vector<char> row1{'a', 'b', 'c', 'e'};
  vector<char> row2{'s', 'f', 'c', 's'};
  vector<char> row3{'a', 'd', 'e', 'e'};
  vector<vector<char>> test{row1, row2, row3};
  vector<string> words{"as","ab","cf","da","ee","e","adee","eeda"};

  auto ret = so.wordSearchII(test, words);
  for (auto s : ret)
    cout << s << endl;

  return 0;
}
