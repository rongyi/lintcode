// http://www.lintcode.com/zh-cn/problem/copy-list-with-random-pointer

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
  /**
   * @param head: The head of linked list with a random pointer.
   * @return: A new head of a deep copy of the list.
   */
  RandomListNode *copyRandomList(RandomListNode *head) {
    for (RandomListNode *cur = head; cur;) {
      // 穿插在之间，奇数节点为原来的，偶数节点为新建的
      RandomListNode *node = new RandomListNode(cur->label);
      node->next = cur->next;
      cur->next = node;
      cur = node->next;
    }
    for (RandomListNode *cur = head; cur;) {
      if (cur->random)
        cur->next->random = cur->random->next;
      cur = cur->next->next;
    }
    // 分拆两个单链表
    RandomListNode dummy(-1);
    for (RandomListNode *cur = head, *new_cur = &dummy;
         cur;) {
      new_cur->next = cur->next;
      new_cur = new_cur->next;
      cur->next = cur->next->next;
      cur = cur->next;
    }
    return dummy.next;
  }
};
