// http://www.lintcode.com/zh-cn/problem/reverse-linked-list

/**
 * Definition of ListNode
 *
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
  /**
   * @param head: The first node of linked list.
   * @return: The new head of reversed linked list.
   */
  ListNode *reverse(ListNode *head) {
    if (!head)
      return NULL;
    ListNode dummy;
    dummy.next = head;
    ListNode *p = head;
    ListNode *q = head->next;

    p->next = NULL;
    dummy.next = p;

    while (q) {
      ListNode *r = q->next;
      q->next = dummy.next;
      dummy.next = q;
      q = r;
    }
    return dummy.next;
  }
};
