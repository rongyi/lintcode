// http://www.lintcode.com/zh-cn/problem/flatten-nested-list-iterator
#include <stack>
#include <vector>
using std::stack;
using std::vector;
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    for (int i = nestedList.size() - 1; i >= 0; i--) {
      s.push(nestedList[i]);
    }
  }

  // @return {int} the next element in the iteration
  int next() {
    NestedInteger t = s.top();
    s.pop();
    return t.getInteger();
  }

  // @return {boolean} true if the iteration has more element or false
  bool hasNext() {
    while (!s.empty()) {
      NestedInteger t = s.top();
      if (t.isInteger()) {
        return true;
      }
      s.pop();
      for (int i = t.getList().size() - 1; i >= 0; --i) {
        s.push(t.getList()[i]);
      }
    }
  }

private:
  stack<NestedInteger> s;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) v.push_back(i.next());
 */
