/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
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
#include <climits>
class Solution {
 public:
  int findBottomLeftValue(TreeNode* root) {
    int ans{-1};
    int maxDepth{-1};
    auto bfs = [&](this auto&& bfs, TreeNode* cur, int depth) {
      if (!cur) {
        return;
      }
      if (depth > maxDepth) {
        maxDepth = depth;
        ans = cur->val;
      }
      bfs(cur->left, depth + 1);
      bfs(cur->right, depth + 1);

      return;
    };
    bfs(root, 0);
    return ans;
  }
};
// @lc code=end
