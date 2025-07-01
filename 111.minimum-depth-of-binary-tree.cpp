/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
  int minDepth(TreeNode *root) {
    int res = INT_MAX;
    if (!root) {
      res = 0;
    }
    auto dfs = [&](this auto &&dfs, int depth, TreeNode *cur) {
      if (!cur) {
        return;
      }
      if (cur && !cur->left && !cur->right) {
        res = std::min(res, depth);
        return;
      }
      dfs(depth + 1, cur->left);
      dfs(depth + 1, cur->right);
    };
    int dep = 1;
    dfs(dep, root);
    return res;
  }
};
// @lc code=end
