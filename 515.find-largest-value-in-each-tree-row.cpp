/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] Find Largest Value in Each Tree Row
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
#include <vector>
class Solution {
public:
  std::vector<int> largestValues(TreeNode *root) {
    std::vector<int> ans;
    auto bfs = [&](this auto &&bfs, int depth, TreeNode *cur) {
      if (!cur)
        return;
      if (depth == ans.size()) {
        ans.push_back(INT_MIN);
      }
      ans[depth] = max(ans[depth], cur->val);
      bfs(depth + 1, cur->left);
      bfs(depth + 1, cur->right);
    };
    bfs(0, root);
    return ans;
  }
};
// @lc code=end
