/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
#include <vector>
class Solution {
public:
  std::vector<int> rightSideView(TreeNode *root) {
    std::vector<int> ans;
    TreeNode *nxt;
    int depth_L = 0;
    int depth_R = 0;
    auto bfs = [&](this auto &&bfs, int depth, TreeNode *cur, int &count) {
      if (!cur) {
        return;
      }
      if (ans.size() == depth) {
        ans.push_back(cur->val);
      }
      count++;
      bfs(depth + 1, cur->right, count);
      bfs(depth + 1, cur->left, count);
    };
    bfs(0, root, depth_R);
    return ans;
  }
};
// @lc code=end
