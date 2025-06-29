/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
  Node *connect(Node *root) {
    if (!root)
      return nullptr;

    Node *cur = root;

    while (cur) {
      Node dummy(0); // 本层的虚拟头节点
      Node *tail = &dummy;

      while (cur) {
        if (cur->left) {
          tail->next = cur->left;
          tail = tail->next;
        }
        if (cur->right) {
          tail->next = cur->right;
          tail = tail->next;
        }
        cur = cur->next; // 遍历当前层
      }

      cur = dummy.next; // 进入下一层
    }

    return root;
  }
};
// @lc code=end
