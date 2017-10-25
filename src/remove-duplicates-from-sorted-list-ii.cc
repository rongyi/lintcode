// http://www.lintcode.com/zh-cn/problem/remove-duplicates-from-sorted-list-ii

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
    if (!head || !head->next)
      return head;

    ListNode *p = head->next;
    if (head->val == p->val) {
      while (p && head->val == p->val) {
        ListNode *tmp = p;
        p = p->next;
        delete tmp;
      }
      delete head; // clear all
      return deleteDuplicates(p);
    } else {
      head->next = deleteDuplicates(head->next);
      return head;
    }
  }
};
