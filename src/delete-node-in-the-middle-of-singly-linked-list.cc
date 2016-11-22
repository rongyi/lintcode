// http://www.lintcode.com/zh-cn/problem/delete-node-in-the-middle-of-singly-linked-list/

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
   * @param node: a node in the list should be deleted
   * @return: nothing
   */
  void deleteNode(ListNode *node) {
    if (!node)
      return;
    if (node->next) {
      node->val = node->next->val;
      node->next = node->next->next;
      //delete node->next;
    }
  }
};
