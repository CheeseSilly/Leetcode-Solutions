/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
#include <string>
#include <vector>
class Solution {
public:
  std::vector<std::string> binaryTreePaths(TreeNode *root) {
    std::vector<std::string> ans;
    // use path to store the main route
    auto bfs = [&](this auto &&bfs, TreeNode *cur, std::string path) {
      if (!cur) {

        return;
      }
      if (cur->left || cur->right) {
        std::string str = std::to_string(cur->val);
        str += "->";
        path += str;
      } else {
        std::string str = std::to_string(cur->val);
        path += str;
        ans.push_back(path);
        path = "";
      }
      bfs(cur->left, path);
      bfs(cur->right, path);
    };
    bfs(root, std::string(""));
    return ans;
  }
};
// @lc code=end
