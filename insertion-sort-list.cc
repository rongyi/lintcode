// http://www.lintcode.com/zh-cn/problem/insertion-sort-list

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
   * @return: The head of linked list.
   */
  ListNode *insertionSortList(ListNode *head) {
    ListNode dummy(INT_MIN);
    for (ListNode *cur = head; cur != nullptr;) {
      auto pos = find_insert_pos(&dummy, cur->val);
      ListNode *tmp = cur->next;
      cur->next = pos->next;
      pos->next = cur;
      cur = tmp;
    }
    return dummy.next;
  }
private:
  ListNode *find_insert_pos(ListNode *head, int x) {
    ListNode *pre = nullptr;
    for (ListNode *cur = head; cur != nullptr && cur->val <= x;
         pre = cur, cur = cur->next)
      ;
    return pre;
  }
};
