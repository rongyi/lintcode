// http://www.lintcode.com/zh-cn/problem/partition-list

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
   * @param x: an integer
   * @return: a ListNode
   */
  ListNode *partition(ListNode *head, int x) {
    ListNode left_dummy(-1);
    ListNode right_dummy(-1);
    auto left_cur = &left_dummy;
    auto right_cur = &right_dummy;

    for (ListNode *cur = head; cur; cur = cur->next) {
      if (cur->val < x) {
        left_cur->next = cur;
        left_cur = cur;
      } else {
        right_cur->next = cur;
        right_cur = cur;
      }
    }

    left_cur->next = right_dummy.next;
    right_cur->next = nullptr;

    return left_dummy.next;
  }
};
