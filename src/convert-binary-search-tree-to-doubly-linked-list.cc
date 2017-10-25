// http://www.lintcode.com/zh-cn/problem/convert-binary-search-tree-to-doubly-linked-list

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 * Definition of Doubly-ListNode
 * class DoublyListNode {
 * public:
 *     int val;
 *     DoublyListNode *next, *prev;
 *     DoublyListNode(int val) {
 *         this->val = val;
 this->prev = this->next = NULL;
 *     }
 * }
 */
class TreeNode {
public:
  int val;
  TreeNode *left, *right;
  TreeNode(int val) {
    this->val = val;
    this->left = this->right = nullptr;
  }
};

class DoublyListNode {
public:
  int val;
  DoublyListNode *next, *prev;
  DoublyListNode(int val) {
    this->val = val;
    this->prev = this->next = nullptr;
  }
};

class Solution {
public:
  Solution() : head_(nullptr), return_(nullptr) {}
  /**
   * @param root: The root of tree
   * @return: the head of doubly list node
   */
  typedef void (*visitor)(const TreeNode *root);
  DoublyListNode *bstToDoublyList(TreeNode *root) {
    inorder(root);
    return return_;
  }
  ~Solution() {
    while (return_) {
      delete return_;
      DoublyListNode *next = return_->next;
      return_ = next;
    }
  }

private:
  void inorder(const TreeNode *root) {
    if (!root) {
      return;
    }
    inorder(root->left);
    chain(root);
    inorder(root->right);
  }
  void chain(const TreeNode *root) {
    int val = root->val;
    DoublyListNode *new_node = new DoublyListNode(val);
    // first node
    if (!head_) {
      head_ = new_node;
      return_ = new_node;
    } else {
      head_->next = new_node;
      new_node->prev = head_;
      head_ = new_node;
    }
  }

private:
  DoublyListNode *head_;
  DoublyListNode *return_;
};
