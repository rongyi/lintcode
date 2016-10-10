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
    this->left = this->right = nullptr;
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
    vector<string> nodes;
    split(',', data, nodes);

    const int n = nodes.size();
    if (n == 0)
      return nullptr;

    TreeNode *root = build(nodes[0]);
    if (!root)
      return root;

    doDeserilize(root, nodes, 0, n);

    return root;
  }

private:
  TreeNode *build(std::string sval) {
    if (sval == "#")
      return nullptr;

    int val = std::stoi(sval);
    TreeNode *new_node = new TreeNode(val);
    return new_node;
  }

  void doDeserilize(TreeNode *root, vector<string> &nodes, int index, int n) {
    if (!root)
      return;
    int left_index = 2 * index + 1;
    int right_index = left_index + 1;

    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    if (left_index < n && root) {
      left = build(nodes[left_index]);
      root->left = left;
    }

    if (right_index < n && root) {
      right = build(nodes[right_index]);
      root->right = right;
    }
    if (left) {
      doDeserilize(left, nodes, left_index, n);
    }
    if (right) {
      doDeserilize(right, nodes, right_index, n);
    }
  }
  /* like python split
   */
  inline void split(const char delim, const std::string &input, std::vector<std::string> &output) {
    if (input.empty())
      return;

    output.clear();
    size_t token_start_pos = 0;
    size_t token_size = 0;

    for (size_t i = 0; i <= input.size() - 1; ++i) {
      if (input[i] == delim) {
        if (token_size > 0) {
          output.push_back(std::string(input, token_start_pos, token_size));
        }
        token_start_pos = i + 1;
        token_size = 0;
      } else {
        ++token_size;
      }
    }

    // the last one
    token_size = input.size() - token_start_pos;
    if (token_size > 0) {
      output.push_back(std::string(input, token_start_pos, token_size));
    }
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

  auto tree = so.deserialize(ret);

  ret = so.serialize(tree);
  cout << ret << endl;

  // auto test_tree = so.deserialize("21##3##");

  return 0;
}
