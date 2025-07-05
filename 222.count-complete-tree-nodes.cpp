/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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
  int countNodes(TreeNode *root) {
    int count = 0;
    auto bfs = [&](this auto &&bfs, TreeNode *cur) {
      if (!cur)
        return;
      count++;
      bfs(cur->left);
      bfs(cur->right);
    };
    bfs(root);
    return count;
  }
};
// @lc code=end
