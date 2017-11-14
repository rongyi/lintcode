// http://www.lintcode.com/zh-cn/problem/binary-tree-longest-path-with-same-value

#include <bitset>
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  /*
   * @param : as indicated in the description
   * @param : as indicated in the description
   * @return: Return the number of edges on the longest path with same value.
   * http://blog.csdn.net/kaaokou/article/details/78351672
   */
  int LongestPathWithSameValue(vector<int> &A, vector<int> &E) {
    // write your code here
    N_ = A.size();
    adj_ = vector<vector<int>>(N_);
    //输入数据处理,把边保存到adj里面
    for (int i = 0; i < N_ - 1; i++) {
      //构造adj
      addEdge(E[i * 2] - 1, E[i * 2 + 1] - 1);
    }

    for (int i = 0; i < N_; i++) {
      //建立一个容器marked判断节点i是否被访问过
      vector<bool> marked(N_, false);
      depth(A, marked, i);
    }
    return ret_;
  }
  int depth(vector<int> &A, vector<bool> &marked, int index) {
    int L = 0, R = 0;
    marked[index] = true;
    bool flag = true;
    //在与index相连接的节点里面寻找值相等并且没有被访问过的点，深度搜索
    for (int j : adj_[index]) {
      //判断节点值是否与index的值相等
      if (A[j] == A[index] && marked[j] == false) {
        //无法得知节点j是Index的左节点还是右节点
        //但是这里只求路径长度，可以假定第一个匹配到的为左，第二个为右；
        if (flag) {
          L = depth(A, marked, j) + 1;
          flag = false;
        } else {
          R = depth(A, marked, j) + 1;
        }
      }
    }
    //这个处理过程和二叉树的最大路径和类似，这里就不再多说了
    ret_ = std::max(ret_, L + R);
    return std::max(L, R);
  }
  void addEdge(int v, int w) {
    adj_[v].push_back(w);
    adj_[w].push_back(v);
  }

private:
  // N为节点数
  // adj_[i]存储与i相连接的节点编号
  int ret_ = 0;
  int N_;
  vector<vector<int>> adj_;
};
