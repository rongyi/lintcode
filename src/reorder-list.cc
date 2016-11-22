// http://www.lintcode.com/zh-cn/problem/reorder-list

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
   * @return: void
   */
  void reorderList(ListNode *head) {
    if (!head || !head->next)
      return;
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *prev = nullptr;

    while (fast && fast->next) {
      prev = slow;
      slow  = slow->next;
      fast = fast->next->next;
    }
    prev->next = nullptr; // 上半截列表的最后一个节点，从这里断开了

    slow = reverse(slow);
    ListNode *curr = head;
    while (curr->next) {
      ListNode *tmp = curr->next;
      curr->next = slow;
      slow = slow->next;
      curr->next->next = tmp;
      curr = tmp;
    }
    curr->next = slow;
  }
  ListNode *reverse(ListNode *head) {
    if (!head || !head->next)
      return head;
    ListNode *prev = head;
    for (ListNode *curr = head->next, *next = curr->next; curr;
         prev = curr, curr = next, next = next ? next->next : nullptr) {
      curr->next = prev;
    }
    head->next = nullptr;

    return prev;
  }
};
