/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] Maximum Binary Tree
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
#include <iterator>
#include <vector>
class Solution {
public:
  TreeNode *constructMaximumBinaryTree(std::vector<int> &nums) {
    if (nums.empty())
      return nullptr;

    auto maxNum = std::max_element(nums.begin(), nums.end());
    auto dis = std::distance(nums.begin(), maxNum);
    auto leftNums = std::vector<int>(nums.begin(), nums.begin() + dis);
    auto rightNums = std::vector<int>(nums.begin() + 1 + dis, nums.end());
    int max_num = *maxNum;
    TreeNode *root = new TreeNode(max_num);
    root->left = constructMaximumBinaryTree(leftNums);
    root->right = constructMaximumBinaryTree(rightNums);
    return root;
  }
};
// @lc code=end
