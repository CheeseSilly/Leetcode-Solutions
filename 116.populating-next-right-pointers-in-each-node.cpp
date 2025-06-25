/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
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
    auto bfs = [&](this auto &&bfs, Node *cur) {
      if (!root || !cur->left || !cur->right) {
        return;
      }
      cur->left->next = cur->right;
      if (cur->next) {
        cur->right->next = cur->next->left;
      }
      bfs(cur->left);
      bfs(cur->right);
    };
    bfs(root);
    return root;
  }
};
// @lc code=end
