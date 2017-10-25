// http://www.lintcode.com/zh-cn/problem/rehashing
#include <iostream>
#include <string>
#include <vector>

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
  vector<ListNode *> rehashing(vector<ListNode *> hashTable) {
    auto hash = [](int key, int capacity) -> int {
      return (key % capacity + capacity) % capacity;
      // return key % capacity;
    };

    vector<ListNode *> ret;
    const int kOriginSize = hashTable.size();
    const int kCurrentSize = kOriginSize * 2;
    if (kOriginSize == 0)
      return ret;

    ret.resize(kOriginSize * 2);

    for (int i = 0; i < kOriginSize; i++) {
      for (ListNode *head = hashTable[i]; head != nullptr; head = head->next) {
        int curKey = hash(head->val, kCurrentSize);
        insertList(ret, curKey, new ListNode(head->val));
      }
    }

    return ret;
  }

  void insertList(vector<ListNode *> &hashTable, int index, ListNode *node) {
    ListNode *cur_head = hashTable[index];
    if (!cur_head) {
      hashTable[index] = node;
    } else {
      insertListTail(cur_head, node);
    }
  }
  // insert at linklist head
  void insertList(ListNode *head, ListNode *node) {
    node->next = head->next;
    head->next = node;
  }
  // insert at linklist tail, insert at tail seems right
  void insertListTail(ListNode *head, ListNode *node) {
    ListNode *cur = head;
    while (cur->next)
      cur = cur->next;
    cur->next = node;
  }
};
