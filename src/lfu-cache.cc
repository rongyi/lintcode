// http://www.lintcode.com/zh-cn/problem/lfu-cache
#include <list>
#include <unordered_map>
using std::list;
using std::unordered_map;

class LFUCache{
public:
  // @param capacity, an integer
  LFUCache(int capacity) {
    capacity_ = capacity;
    cur_size_ = 0;
  }

  // @param key, an integer
  // @param value, an integer
  // @return nothing
  void set(int key, int value) {
    if (capacity_ <= 0)
      return;
    // contain this key
    if (cache_map_.find(key) != cache_map_.end()) {
      // update value
      cache_map_[key].value_ = value;
      // update freq
      freq_map_[cache_map_[key].freq_].erase(position_map_[key]);
      cache_map_[key].freq_++;

      freq_map_[cache_map_[key].freq_].push_back(key);

      if (freq_map_[min_freq_].size() == 0) {
        min_freq_ = cache_map_[key].freq_;
      }
      position_map_[key] = --freq_map_[cache_map_[key].freq_].end();
      return;
    }
    // evict the least freq if nessary
    if (cur_size_ >= capacity_) {
      cache_map_.erase(freq_map_[min_freq_].front());
      position_map_.erase(freq_map_[min_freq_].front());
      freq_map_[min_freq_].pop_front();
      cur_size_--;
    }
    // insert
    min_freq_ = 1;
    cache_map_[key] = CacheNode(key, value);
    freq_map_[1].push_back(key);
    position_map_[key] = --freq_map_[1].end();

    cur_size_++;
  }

  // @return an integer
  int get(int key) {
    if (cache_map_.find(key) == cache_map_.end()) {
      return -1;
    }
    freq_map_[cache_map_[key].freq_].erase(position_map_[key]);
    cache_map_[key].freq_++;
    freq_map_[cache_map_[key].freq_].push_back(key);
    position_map_[key] = --freq_map_[cache_map_[key].freq_].end();

    if (freq_map_[min_freq_].size() == 0) {
      min_freq_ = cache_map_[key].freq_;
    }

    return cache_map_[key].value_;
  }

private:
  struct CacheNode {
    int key_;
    int value_;
    int freq_;
    CacheNode(int k, int v) : key_(k), value_(v), freq_(1) {}
    CacheNode() : key_(0), value_(0), freq_(0){}
  };

  int capacity_;
  int min_freq_;
  int cur_size_;
  unordered_map<int, CacheNode> cache_map_;
  unordered_map<int, list<int>::iterator> position_map_;
  unordered_map<int, list<int>> freq_map_;
};

int main()
{
  LFUCache cache(1);
  cache.set(1, 1);
  return 0;
}
