// http://www.lintcode.com/zh-cn/problem/insert-delete-getrandom-o1
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class RandomizedSet {
public:
  RandomizedSet() {
    // do initialize if necessary
  }

  // Inserts a value to the set
  // Returns true if the set did not already contain the specified element or false
  bool insert(int val) {
    if (num_index_dict_.find(val) != num_index_dict_.end()) {
      return false;
    }
    nums_.push_back(val);
    num_index_dict_[val] = nums_.size() - 1;
    return true;
  }

  // Removes a value from the set
  // Return true if the set contained the specified element or false
  bool remove(int val) {
    if (num_index_dict_.find(val) == num_index_dict_.end()) {
      return false;
    }
    int last = nums_.back();
    // overwrite val and delete the last
    nums_[num_index_dict_[val]] = last;
    num_index_dict_[last] = num_index_dict_[val];

    nums_.pop_back();
    // delete the val entrance point
    num_index_dict_.erase(val);

    return true;
  }

  // Get a random element from the set
  int getRandom() {
    return nums_[rand() % nums_.size()];
  }
private:
  vector<int> nums_;
  std::unordered_map<int, int> num_index_dict_;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param = obj.insert(val);
 * bool param = obj.remove(val);
 * int param = obj.getRandom();
 */
