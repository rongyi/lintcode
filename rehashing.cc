// http://www.lintcode.com/zh-cn/problem/rehashing
#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */

class ListNode {
public:
  int val;
  ListNode *next;
  ListNode(int val) {
    this->val = val;
    this->next = NULL;
  }
};

class Solution {
public:
  /**
   * @param hashTable: A list of The first node of linked list
   * @return: A list of The first node of linked list which have twice size
   */
  vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
    vector<ListNode*> ret;
    const int kOriginSize = hashTable.size();
    const int kCurrentSize = kOriginSize * 2;
    if (kOriginSize == 0)
      return ret;

    ret.resize(kOriginSize * 2);
    return ret;
  }
};
