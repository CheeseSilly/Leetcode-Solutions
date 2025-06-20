/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
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
#include <queue>
#include <vector>
class Solution {
public:
  std::vector<std::vector<int>> levelOrderBottom(TreeNode *root) {
    if (!root) {
      return {};
    }
    std::vector<std::vector<int>> ans;
    std::queue<TreeNode *> qe;
    qe.push(root);
    while (!qe.empty()) {
      std::vector<int> vals;
      for (int n = qe.size(); n--;) {
        auto tmp = qe.front();
        qe.pop();
        vals.push_back(tmp->val);
        if (tmp->left)
          qe.push(tmp->left);
        if (tmp->right)
          qe.push(tmp->right);
      }
      ans.push_back(vals);
    }
    std::ranges::reverse(ans);
    return ans;
  }
};
// @lc code=end
