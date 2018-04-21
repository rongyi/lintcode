// http://www.lintcode.com/zh-cn/problem/top-k-frequent-words
#include <vector>
#include <iostream>
#include <string>
#include <bitset>
#include <queue>
#include <unordered_map>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /**
   * @param words: an array of string
   * @param k: An integer
   * @return: an array of string
   */
  vector<string> topKFrequentWords(vector<string> &words, int k) {
    std::unordered_map<string, int> wfd;
    for (auto &s : words) {
      wfd[s]++;
    }
    std::unordered_map<int, vector<string>> freqd;
    for (auto &kv : wfd) {
      if (freqd.find(kv.second) == freqd.end()) {
        freqd[kv.second] = vector<string>{kv.first};
      } else {
        freqd[kv.second].push_back(kv.first);
      }
    }
    std::priority_queue<int, vector<int>, std::less<int>> max_heap;
    for (auto &kv : freqd) {
      max_heap.push(kv.first);
    }

    for (auto &d: wfd) {
      cout << d.first << ":" << d.second << endl;
    }

    // return pq.top();
    auto ret = vector<string>{};
    // example
    // code:4
    // lint:3
    // baby:2
    // yes:2
    // body:1
    // chrome:1
    // safari:1
    // you:1
    // k has a meaning of count, so when k is 3 after we push baby, we drop yes and return
    unsigned origink = k;
    while (k--) {
      auto current = max_heap.top();
      auto words = freqd[current];
      if (words.size() > 1) {
        std::sort(words.begin(), words.end());
      }
      for (auto &s : words) {
        ret.push_back(s);
        if (ret.size() == origink) {
          return ret;
        }
      }
      max_heap.pop();
    }
    return ret;

  }
};

int main() {
  Solution so;
  vector<string> test{"yes", "lint", "code",
                      "yes", "code", "baby",
                      "you", "baby", "chrome",
                      "safari", "lint", "code",
                      "body", "lint", "code"};
  auto test_ret = so.topKFrequentWords(test, 3);
  for (auto &s : test_ret) {
    cout << s << endl;
  }
}
