// http://www.lintcode.com/zh-cn/problem/convert-sorted-list-to-balanced-bst

class Solution {
public:
  /**
   * @param head: The first node of linked list.
   * @return: a tree node
   */
  TreeNode *sortedListToBST(ListNode *head) {
    int len = 0;
    ListNode *p = head;
    while (p) {
      len++;
      p = p->next;
    }

    return sortedListToBST(head, 0, len - 1);
  }

private:
  TreeNode *sortedListToBST(ListNode *&list, int start, int end) {
    if (start > end)
      return nullptr;
    int mid = start + (end - start) / 2;
    TreeNode *left_child = sortedListToBST(list, start, mid - 1);
    TreeNode *parent = new TreeNode(list->val);
    parent->left = left_child;
    list = list->next;
    parent->right = sortedListToBST(list, mid + 1, end);
    return parent;
  }
};
