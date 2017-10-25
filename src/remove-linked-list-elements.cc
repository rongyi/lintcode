// http://www.lintcode.com/zh-cn/problem/remove-linked-list-elements/
class Solution {
public:
  /**
   * @param head a ListNode
   * @param val an integer
   * @return a ListNode
   */
  ListNode *removeElements(ListNode *head, int val) {
    ListNode dummy(-1);
    dummy.next = head;

    ListNode *pre = &dummy;
    ListNode *cur = head;

    while (cur) {
      // clean all the occurrence of this val, so we don't change prev pointer
      // untill
      // cur->val is not equal to the target value
      if (cur->val == val) {
        pre->next = cur->next;
      } else {
        // normal case, prev keep going and cur keep going, that's it
        pre = pre->next;
      }
      cur = cur->next;
    }

    return dummy.next;
  }
};
