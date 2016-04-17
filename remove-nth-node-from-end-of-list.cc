// http://www.lintcode.com/zh-cn/problem/remove-nth-node-from-end-of-list

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
class Solution {
public:
  /**
   * @param head: The first node of linked list.
   * @param n: An integer.
   * @return: The head of linked list.
   */
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode dummy(-1);
    dummy.next = head;

    ListNode *p = &dummy;
    ListNode *q = &dummy;

    for (int i = 0; i < n; i++)
      q = q->next;

    while (q->next) {
      p = p->next;
      q = q->next;
    }
    ListNode *tmp = p->next;
    p->next = p->next->next;
    delete tmp;
    return dummy.next;
  }
};
