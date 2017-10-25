// http://www.lintcode.com/zh-cn/problem/sort-list

class Solution {
public:
  /**
   * @param head: The first node of linked list.
   * @return: You should return the head of the sorted linked list,
   using constant space complexity.
  */
  ListNode *sortList(ListNode *head) {
    if (!head || head->next == nullptr)
      return head;
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
    }
    fast = slow;
    slow = slow->next;    // now slow is the bottom half list's header
    fast->next = nullptr; // split action
    ListNode *l1 = sortList(head);
    ListNode *l2 = sortList(slow);

    return mergeTwoLists(l1, l2);
  }

private:
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
