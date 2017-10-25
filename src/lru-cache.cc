// http://www.lintcode.com/zh-cn/problem/lru-cache

#include <list>
#include <unordered_map>
using std::list;
using std::unordered_map;

class LRUCache {
public:
  // @param capacity, an integer
  LRUCache(int capacity) { this->capacity_ = capacity; }

  // @return an integer
  int get(int key) {
    if (cache_map_.find(key) == cache_map_.end())
      return -1;
    cache_list_.splice(cache_list_.begin(), cache_list_, cache_map_[key]);
    cache_map_[key] = cache_list_.begin();
    return cache_map_[key]->value;
  }

  // @param key, an integer
  // @param value, an integer
  // @return nothing
  void set(int key, int value) {
    // newly add?
    if (cache_map_.find(key) == cache_map_.end()) {
      if (cache_list_.size() == capacity_) {
        cache_map_.erase(cache_list_.back().key);
        cache_list_.pop_back();
      }
      cache_list_.push_front(CacheNode(key, value));
      cache_map_[key] = cache_list_.begin();
    } else { // old item
      cache_map_[key]->value = value;
      cache_list_.splice(cache_list_.begin(), cache_list_, cache_map_[key]);
      cache_map_[key] = cache_list_.begin();
    }
  }

private:
  struct CacheNode {
    int key;
    int value;
    CacheNode(int k, int v) : key(k), value(v) {}
  };
  int capacity_;
  list<CacheNode> cache_list_;
  unordered_map<int, list<CacheNode>::iterator> cache_map_;
};
