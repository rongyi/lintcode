// http://www.lintcode.com/zh-cn/problem/rotate-list

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
   * @param head: the list
   * @param k: rotate to the right k places
   * @return: the list after rotation
   */
  ListNode *rotateRight(ListNode *head, int k) {
    if (head == nullptr || k == 0)
      return head;

    int len = 1;
    ListNode *p = head;
    while (p->next) {
      len++;
      p = p->next; // 这里的结果是p指针落在最后一个节点上，而不是最后节点的next上
    }
    k = len - k % len;

    p->next = head; //收尾相连
    for (int step = 0; step < k; step++) {
      p = p->next;
    }
    head = p->next;
    p->next = nullptr;

    return head;
  }
};
