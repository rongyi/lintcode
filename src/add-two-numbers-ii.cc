#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};



class Solution {
public:
  /**
   * @param l1: the first list
   * @param l2: the second list
   * @return: the sum list of l1 and l2
   */
  ListNode *addLists2(ListNode *l1, ListNode *l2) {
    return reverse(addLists(reverse(l1), reverse(l2)));
  }


private:
  ListNode *reverse(ListNode *head) {
    if (!head)
      return NULL;
    ListNode dummy;
    dummy.next = head;
    ListNode *p = head;
    ListNode *q = head->next;

    p->next = NULL;
    dummy.next = p;

    while (q) {
      ListNode *r = q->next;
      q->next = dummy.next;
      dummy.next = q;
      q = r;
    }
    return dummy.next;
  }

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
