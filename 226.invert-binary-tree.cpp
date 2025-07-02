/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] Invert Binary Tree
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
  TreeNode *invertTree(TreeNode *root) {
    auto dfs = [&](this auto &&dfs, TreeNode *cur) {
      if (!cur || (!cur->left && !cur->right)) {
        return;
      }
      // if (cur->left)
      dfs(cur->left);
      // if (cur->right)
      dfs(cur->right);
      TreeNode *tmp = cur->left;
      cur->left = cur->right;
      cur->right = tmp;
    };
    dfs(root);
    return root;
  }
};
// @lc code=end
