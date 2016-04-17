// http://www.lintcode.com/zh-cn/problem/remove-duplicates-from-sorted-list

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
   * @return: head node
   */
  ListNode *deleteDuplicates(ListNode *head) {
    if (!head)
      return head;
    ListNode *p = head;
    ListNode *q = head->next;
    while (q) {
      ListNode *next = q->next;
      if (p->val == q->val) {
        p->next = next;
        q->next = NULL;
        delete q;
      } else {
        p = q;
      }
      q = next;
    }
    return head;
  }
};
