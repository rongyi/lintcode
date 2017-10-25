// http://www.lintcode.com/zh-cn/problem/flatten-list
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

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
class NestedInteger {
public:
  // Return true if this NestedInteger holds a single integer,
  // rather than a nested list.
  bool isInteger() const;

  // Return the single integer that this NestedInteger holds,
  // if it holds a single integer
  // The result is undefined if this NestedInteger holds a nested list
  int getInteger() const;

  // Return the nested list that this NestedInteger holds,
  // if it holds a nested list
  // The result is undefined if this NestedInteger holds a single integer
  const vector<NestedInteger> &getList() const;
};

class Solution {
public:
  // @param nestedList a list of NestedInteger
  // @return a list of integer
  vector<int> flatten(vector<NestedInteger> &nestedList) {
    vector<int> ret;

    doFlatten(nestedList, ret);

    return ret;
  }

  void doFlatten(const vector<NestedInteger> &nestedList, vector<int> &acc) {
    for (auto n : nestedList) {
      if (n.isInteger()) {
        acc.push_back(n.getInteger());
      } else {
        doFlatten(n.getList(), acc);
      }
    }
  }
};
