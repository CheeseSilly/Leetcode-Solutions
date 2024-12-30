#include <iostream>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  bool isSubPath(ListNode *head, TreeNode *root) {
    ListNode *origin = head;
    return dfs(head, root, origin);
  }

private:
  bool dfs(ListNode *head, TreeNode *root, ListNode *origin) {
    if (head == nullptr) {
      return true;
    }
    if (root == nullptr) {
      return false;
    }
    // 1.match success,step recursively
    // 2.match failed,back to the head(==origin),replace head->next with
    // origin,and step recursively
    return head->val == root->val && (dfs(head->next, root->left, origin) ||
                                      dfs(head->next, root->right, origin)) ||
           head == origin && (dfs(origin, root->left, origin) ||
                              dfs(origin, root->right, origin));
  }
};