/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
#include <functional>
#include <vector>
class Solution {
public:
  bool isSymmetric(TreeNode *root) {
    std::function<bool(TreeNode *, TreeNode *)> bfs = [&](TreeNode *l,
                                                          TreeNode *r) -> bool {
      if (!l || !r) {
        return l == r;
      }
      return l->val == r->val && bfs(l->left, r->right) &&
             bfs(l->right, r->left);
    };
    return bfs(root->left, root->right);
  }
};
// @lc code=end
