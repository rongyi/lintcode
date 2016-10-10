// http://www.lintcode.com/zh-cn/problem/binary-tree-serialization
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <queue>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::queue;


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
public:
  /**
   * This method will be invoked first, you should design your own algorithm
   * to serialize a binary tree which denote by a root node to a string which
   * can be easily deserialized by your own "deserialize" method later.
   */
  string serialize(TreeNode *root) {
    std::stringstream ss;
    if (!root)
      return "";
    queue<TreeNode *> aux;
    aux.push(root);

    while (!aux.empty()) {
      auto cur_node = aux.front();
      if (cur_node) {
        ss << cur_node->val << ",";
        if (cur_node->left) {
          aux.push(cur_node->left);
        } else {
          aux.push(nullptr);
        }

        if (cur_node->right) {
          aux.push(cur_node->right);
        } else {
          aux.push(nullptr);
        }
      } else {
        ss << "#,";
      }
      aux.pop();
    }

    return ss.str();
  }

  /**
   * This method will be invoked second, the argument data is what exactly
   * you serialized at method "serialize", that means the data is not given by
   * system, it's given by your own serialize method. So the format of data is
   * designed by yourself, and deserialize it here as you serialize it in
   * "serialize" method.
   */
  TreeNode *deserialize(string data) {
    if (data.empty())
      return nullptr;
    TreeNode *root = new TreeNode(data[0] - '0');

    do_deseri(data.substr(1), root);

    return root;
  }

private:
  void do_deseri(string data, TreeNode * root) {
    if (data.empty())
      return;

  }
};


int main()
{
  Solution so;
  TreeNode five(5), three(3), one(1), four(4), eight(8), nine(9);
  five.left = &three;
  five.right = &eight;

  three.left = &one;
  three.right = &four;

  eight.right = &nine;


  auto ret = so.serialize(&five);
  cout << ret << endl;

  // auto test_tree = so.deserialize("21##3##");

  return 0;
}
