// http://www.lintcode.com/zh-cn/problem/palindrome-linked-list
#include <stack>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
using std::stack;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  /**
   * @param head a ListNode
   * @return a boolean
   */
  bool isPalindrome(ListNode* head) {
    if (!head || !head->next)
      return true;
    ListNode *slow = head;
    ListNode *fast = head;
    stack<int> aux;
    aux.push(head->val);
    while (fast->next && fast->next->next) {
      slow = slow->next;
      fast = fast->next->next;
      aux.push(slow->val);
    }
    // odd?
    if (!fast->next)
      aux.pop();
    while (slow->next) {
      slow = slow->next;
      int tmp = aux.top();
      aux.pop();
      if (tmp != slow->val)
        return false;
    }
    return true;
  }
};
