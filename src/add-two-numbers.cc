// http://www.lintcode.com/zh-cn/problem/add-two-numbers

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
   * @param l1: the first list
   * @param l2: the second list
   * @return: the sum list of l1 and l2
   */
  ListNode *addLists(ListNode *l1, ListNode *l2) {
    ListNode dummy(-1);
    int carry = 0;
    ListNode *prev = &dummy;

    for (ListNode *pa = l1, *pb = l2;
         pa != nullptr || pb != nullptr;
         pa = pa == nullptr ? nullptr : pa->next,
           pb = pb == nullptr ? nullptr : pb->next,
           prev = prev->next) {
      const int ai = pa == nullptr ? 0 : pa->val;
      const int bi = pb == nullptr ? 0 : pb->val;
      const int value  = (ai + bi + carry) % 10;
      carry = (ai + bi + carry) / 10;
      prev->next = new ListNode(value);
    }
    if (carry > 0)
      prev->next = new ListNode(1);

    return dummy.next;
  }
};
