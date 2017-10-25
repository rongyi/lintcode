// http://www.lintcode.com/zh-cn/problem/mock-hanoi-tower-by-stacks
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::stack;

class Tower {
public:
  // create three towers (i from 0 to 2)
  Tower(int i) {}

  // Add a disk into this tower
  void add(int d) {
    if (!disks_.empty() && disks_.top() <= d) {
      printf("Error placing disk %d", d);
    } else {
      disks_.push(d);
    }
  }

  // @param t a tower
  // Move the top disk of this tower to the top of t.
  void moveTopTo(Tower &t) {
    t.add(disks_.top());
    disks_.pop();
  }

  // @param n an integer
  // @param destination a tower
  // @param buffer a tower
  // Move n Disks from this tower to destination by buffer tower
  void moveDisks(int n, Tower &destination, Tower &buffer) {
    if (n > 0) {
      moveDisks(n - 1, buffer, destination);
      moveTopTo(destination);
      buffer.moveDisks(n - 1, destination, *this);
    }
  }

  stack<int> getDisks() { return disks_; }

private:
  stack<int> disks_;
};
/**
 * Your Tower object will be instantiated and called as such:
 * vector<Tower> towers;
 * for (int i = 0; i < 3; i++) towers.push_back(Tower(i));
 * for (int i = n - 1; i >= 0; i--) towers[0].add(i);
 * towers[0].moveDisks(n, towers[2], towers[1]);
 * print towers[0], towers[1], towers[2]
 */
