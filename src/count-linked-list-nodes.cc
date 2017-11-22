// http://www.lintcode.com/zh-cn/problem/count-linked-list-nodes
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
  /*
  * @param head: the first node of linked list.
  * @return: An integer
  */
  int countNodes(ListNode * head) {
    int ret = 0;
    ListNode *p = head;
    while (p) {
      ++ret;
      p = p->next;
    }
    return ret;
  }
};
