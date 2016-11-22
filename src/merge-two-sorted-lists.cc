// http://www.lintcode.com/zh-cn/problem/merge-two-sorted-lists

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
   * @param ListNode l1 is the head of the linked list
   * @param ListNode l2 is the head of the linked list
   * @return: ListNode head of linked list
   */
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (!l1)
      return l2;
    if (!l2)
      return l1;
    ListNode dummy(-1);
    ListNode *p = &dummy;
    for (; l1 != nullptr && l2 != nullptr; p = p->next) {
      if (l1->val > l2->val) {
        p->next = l2;
        l2 = l2->next;
      } else {
        p->next = l1;
        l1 = l1->next;
      }
    }
    p->next = l1 != nullptr ? l1 : l2;

    return dummy.next;
  }
};
