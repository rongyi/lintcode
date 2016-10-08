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
    auto hash = [] (int key, int capacity) -> int {
      return (key % capacity + capacity) % capacity;
      // return key % capacity;
    };

    vector<ListNode*> ret;
    const int kOriginSize = hashTable.size();
    const int kCurrentSize = kOriginSize * 2;
    if (kOriginSize == 0)
      return ret;

    ret.resize(kOriginSize * 2);
    for (int i = 0; i < kOriginSize; i++) {
      // head
      ListNode *head = hashTable[i];
      if (!head)
        continue;

      int curKey = hash(head->val, kCurrentSize);
      insertList(ret, curKey, new ListNode(head->val));
      // tail
      head = head->next;
      while (head != nullptr) {
        int curKey = hash(head->val, kCurrentSize);
        insertList(ret, curKey, new ListNode(head->val));

        head = head->next;
      }
    }

    return ret;
  }

  void insertList(vector<ListNode*> &hashTable, int index, ListNode *node) {
    ListNode *cur_head = hashTable[index];
    if (!cur_head) {
      hashTable[index] = node;
    } else {
      insertList(cur_head, node);
    }
  }
  // insert at linklist head
  void insertList(ListNode *head, ListNode *node) {
    node->next = head->next;
    head->next = node;
  }
};

// [80->null,null,null,null,null,null,null,null,null,49->null,10->50->null,null,12->null,53->93->133->null,null,15->null,null,null,null,139->null,null,null,null,null,null,null,null,187->null,null,109->null,-10->null,null,null,153->null,null,null,36->null,-3->null,118->null,159->null]

// [80->null,null,null,null,null,null,null,null,null,49->null,10->50->null,null,12->null,53->133->93->null,null,15->null,null,null,null,139->null,null,null,null,null,null,null,null,187->null,null,109->null,-10->null,null,null,153->null,null,null,36->null,-3->null,118->null,159->null]
