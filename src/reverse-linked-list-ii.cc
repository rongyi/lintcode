// http://www.lintcode.com/zh-cn/problem/reverse-linked-list-ii

#include <vector>

using std::vector;

/**
 * Definition of singly-linked-list:
 *
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
  /**
   * @param head: The head of linked list.
   * @param m: The start position need to reverse.
   * @param n: The end position need to reverse.
   * @return: The new head of partial reversed linked list.
   */
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    ListNode dummy(-1);
    dummy.next = head;

    ListNode *prev = &dummy;
    for (int i = 0; i < m - 1; ++i) {
      prev = prev->next;
    }
    ListNode *const head2 = prev;

    prev = head2->next;
    ListNode *cur = prev->next;
    for (int i = m; i < n; ++i) {
      prev->next = cur->next;
      cur->next = head2->next;
      head2->next = cur;
      cur = prev->next;
    }

    return dummy.next;
  }
};
