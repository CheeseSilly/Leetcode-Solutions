/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  int sumOfLeftLeaves(TreeNode *root) {
    int sum{0};
    auto bfs = [&](this auto &&bfs, TreeNode *cur) {
      if (!cur)
        return;
      if (cur->left && !cur->left->left && !cur->left->right) {
        sum += cur->left->val;
      }
      bfs(cur->left);
      bfs(cur->right);
    };
    bfs(root);
    return sum;
  }
};
// @lc code=end
