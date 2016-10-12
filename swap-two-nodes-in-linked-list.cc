// http://www.lintcode.com/zh-cn/problem/swap-two-nodes-in-linked-list
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
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  /**
   * @param head a ListNode
   * @oaram v1 an integer
   * @param v2 an integer
   * @return a new head of singly-linked list
   */
  ListNode* swapNodes(ListNode* head, int v1, int v2) {
    if (!head)
      return nullptr;
    ListNode dummy(-1);
    dummy.next = head;

    ListNode *dhead = &dummy;

    ListNode *v1_prev = search(dhead, v1);
    ListNode *v2_prev = search(dhead, v2);

    // not found
    if (v1_prev == nullptr || v2_prev == nullptr)
      return dummy.next;

    if (v1_prev->next == v2_prev) {
      ListNode *v1 = v1_prev->next;
      ListNode *v2 = v2_prev->next;
      ListNode *v2_next = v2->next;
      v1_prev->next = v2;
      v2->next = v1;
      v1->next = v2_next;
    } else if (v2_prev->next == v1_prev) {
      ListNode *v2 = v2_prev->next;
      ListNode *v1 = v1_prev->next;
      ListNode *v1_next = v1->next;
      v2_prev->next = v1;
      v1->next = v2;
      v2->next = v1_next;
    } else {
      ListNode *pv1 = v1_prev->next;
      ListNode *v1_next = v1_prev->next->next;
      ListNode *v2_next = v2_prev->next->next;

      v1_prev->next = v2_prev->next;
      v2_prev->next->next = v1_next;
      v2_prev->next = pv1;
      pv1->next = v2_next;
    }

    return dummy.next;
  }
  /*
    return the node which its next val is value
    +-------+        +----------+         +-------------+
    |node   +--------> val == value------->             |
    +-------+        +----------+         +-------------+
    return its previous node
  */
  ListNode *search(ListNode *p, int value) {
    while (p->next) {
      if (p->next->val == value)
        break;
      p = p->next;
    }

    return p->next == nullptr ? nullptr : p;
  }
};
