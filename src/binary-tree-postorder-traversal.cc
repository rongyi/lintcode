// http://www.lintcode.com/zh-cn/problem/binary-tree-postorder-traversal
#include <vector>
#include <iostream>
#include <string>
#include <stack>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::stack;


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
 */



class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};
class Solution {
  /**
   * @param root: The root of binary tree.
   * @return: Postorder in vector which contains node values.
   */
public:
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> ret;
    const TreeNode *p, *q;
    stack<const TreeNode *> s;
    p = root;
    do {
      // 有一种斜着往左子树上的链表访问
      while (p != nullptr) {     // 往左下走
        s.push(p);
        p = p->left;
      }
      q = nullptr;
      while (!s.empty()) {
        p = s.top();
        s.pop();
        // 右孩子不存在或已被访问，访问之
        if (p->right == q) {
          ret.push_back(p->val);
          q = p;
        } else {
          // 当前节点不能访问，需再次进栈,其实就是跳到下一个层次的往左下的链表的根节点
          s.push(p);
          p = p->right;
          // 跳到右子树上
          break;
        }
      }
    } while (!s.empty());

    return ret;
  }

private:
  void inner(TreeNode *root, vector<int> &ret) {
    if (!root)
      return;
    inner(root->left, ret);
    inner(root->right, ret);
    ret.push_back(root->val);
  }
};

int main()
{
  Solution so;
  TreeNode r(1), l(2), ri(3);
  r.left = &l;
  r.right = &ri;
  auto ret = so.postorderTraversal(&r);
  return 0;
}
