// http://www.lintcode.com/zh-cn/problem/intersection-of-two-linked-lists
#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;



// * Definition for singly-linked list.

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  /**
   * @param headA: the first list
   * @param headB: the second list
   * @return: a ListNode
   */
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB)
      return nullptr;

    const int lena = Len(headA);
    const int lenb = Len(headB);
    const int the_short = std::min(lena, lenb);
    // A list is the short list
    ListNode *pa = headA;
    ListNode *pb = headB;
    int step = std::abs(lena - lenb);

    // step might be 0!
    if (the_short == lena) {
      while (step) {
        pb = pb->next;
        step--;
      }
    } else {                    // B list is the short list
      while (step) {
        pa = pa->next;
        step--;
      }
    }

    while (pa && pb) {
      // two identical list
      if (pa == pb)
        return pa;
      // if (pa->next == pb->next) {
      //   return pa->next;
      // }
      pa = pa->next;
      pb = pb->next;
    }
    return nullptr;
  }

private:
  size_t Len(const ListNode *node) {
    size_t ret = 0;

    while (node) {
      ret++;
      node = node->next;
    }

    return ret;
  }
};
