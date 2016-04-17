// http://www.lintcode.com/zh-cn/problem/linked-list-cycle

class Solution {
public:
  /**
   * @param head: The first node of linked list.
   * @return: True if it has a cycle, or false
   */
  bool hasCycle(ListNode *head) {
    if (!head)
      return false;
    if (!head->next || !head->next->next)
      return false;
    ListNode *slow = head->next;
    ListNode *fast = head->next;
    while (slow && fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        return true;
      }
    }
    return false;
  }
};
