/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] Average of Levels in Binary Tree
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
#include <numeric>
#include <vector>
class Solution {
public:
  std::vector<double> averageOfLevels(TreeNode *root) {
    std::vector<double> ans;
    std::vector<std::vector<double>> sums;
    auto bfs = [&](this auto &&bfs, int depth, TreeNode *cur) {
      if (!cur) {
        return;
      }
      if (sums.size() == depth) {
        sums.push_back(std::vector<double>());
      }
      sums[depth].push_back(cur->val);
      bfs(depth + 1, cur->left);
      bfs(depth + 1, cur->right);
    };
    bfs(0, root);
    for (auto sum : sums) {
      double mean = std::reduce(sum.begin(), sum.end()) / sum.size();
      ans.push_back(mean);
    }
    return ans;
  }
};
// @lc code=end
