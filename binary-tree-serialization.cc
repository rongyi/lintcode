// http://www.lintcode.com/zh-cn/problem/binary-tree-serialization
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

using std::vector;
using std::cout;
using std::endl;
using std::string;


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

    do_serialize(root, ss);

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
  // using # to denote empty child
  void do_serialize(TreeNode *root, std::stringstream &ss) {
    if (root) {
      ss << root->val;
    }

    if (root->left) {
      do_serialize(root->left, ss);
    } else {
      ss << "#";
    }

    if (root->right) {
      do_serialize(root->right, ss);
    } else {
      ss << "#";
    }
  }

  void do_deseri(string data, TreeNode * root) {
    if (data.empty())
      return;

  }
};


int main()
{
  Solution so;
  TreeNode root(2);
  TreeNode left(1);
  TreeNode right(3);
  root.left = &left;
  root.right = &right;

  TreeNode left_child(0);
  left.left = &left_child;

  auto ret = so.serialize(&root);
  cout << ret << endl;

  auto test_tree = so.deserialize("21##3##");

  return 0;
}
