// http://www.lintcode.com/zh-cn/problem/reverse-nodes-in-k-group/

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
   * @param k an integer
   * @return a ListNode
   */
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (!head || !head->next || k < 2)
      return head;
    ListNode *next_group = head;

    for (int i = 0; i < k; i++) {
      if (next_group)
        next_group = next_group->next;
      else
        return head; // 不够下一个group的，所以这里直接返回
    }

    ListNode *new_next_group = reverseKGroup(next_group, k);

    ListNode *prev = nullptr;
    ListNode *cur = head;
    while (cur != next_group) {
      ListNode *next = cur->next;
      cur->next = prev ? prev : new_next_group;
      prev = cur;
      cur = next;
    }

    return prev;
  }
};
