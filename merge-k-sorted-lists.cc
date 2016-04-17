// http://www.lintcode.com/zh-cn/problem/merge-k-sorted-lists

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
   * @param lists: a list of ListNode
   * @return: The head of one sorted list.
   */
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.size() == 0)
      return nullptr;
    ListNode *p = lists[0];
    for (int i = 1; i < lists.size(); i++) {
      p = mergeTwoLists(p, lists[i]);
    }
    return p;
  }

private:
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
