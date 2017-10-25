// http://www.lintcode.com/zh-cn/problem/swap-nodes-in-pairs/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  /**
   * @param head a ListNode
   * @return a ListNode
   */
  ListNode *swapPairs(ListNode *head) {
    if (!head || !head->next)
      return head;

    ListNode dummy(-1);
    dummy.next = head;

    for (ListNode *prev = &dummy, *cur = prev->next, *next = cur->next; next;
         prev = cur, cur = cur->next, next = cur ? cur->next : nullptr) {
      prev->next = next;
      cur->next = next->next;
      next->next = cur;
    }
    return dummy.next;
  }
};
