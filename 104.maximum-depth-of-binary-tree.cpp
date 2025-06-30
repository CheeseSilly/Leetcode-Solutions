/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
  int maxDepth(TreeNode *root) {
    std::vector<std::vector<int>> ans;
    auto bfs = [&](this auto &&bfs, int depth, TreeNode *cur) {
      if (!cur)
        return;
      if (ans.size() == depth) {
        ans.push_back(std::vector<int>());
      }
      ans[depth].push_back(cur->val);
      bfs(depth + 1, cur->left);
      bfs(depth + 1, cur->right);
    };

    bfs(0, root);

    return ans.size();
  }
};
// @lc code=end
