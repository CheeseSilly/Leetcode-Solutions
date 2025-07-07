/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
#include <algorithm>
#include <climits>
class Solution {
public:
  bool isBalanced(TreeNode *root) {
    bool balanced = true;
    auto bfs = [&](this auto &&bfs, TreeNode *cur) -> int {
      if (!cur) {
        return 0;
      }
      int left = bfs(cur->left);
      int right = bfs(cur->right);
      if (abs(left - right) > 1)
        balanced = false;
      // cur's depth(maybe it can be called height)
      return std::max(left, right) + 1;
    };
    bfs(root);
    return balanced;
  }
};
// @lc code=end
