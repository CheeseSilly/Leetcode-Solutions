/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int, int> in_map;
    for (int i = 0; i < inorder.size(); ++i) {
      in_map[inorder[i]] = i;
    }

    return build(inorder, 0, inorder.size() - 1, postorder, 0,
                 postorder.size() - 1, in_map);
  }

 private:
  TreeNode* build(const vector<int>& inorder, int in_start, int in_end,
                  const vector<int>& postorder, int post_start, int post_end,
                  const unordered_map<int, int>& in_map) {
    if (in_start > in_end || post_start > post_end) {
      return nullptr;
    }

    int root_val = postorder[post_end];
    TreeNode* root = new TreeNode(root_val);

    int in_root_index = in_map.at(root_val);
    int left_size = in_root_index - in_start;

    root->left = build(inorder, in_start, in_root_index - 1, postorder,
                       post_start, post_start + left_size - 1, in_map);
    root->right = build(inorder, in_root_index + 1, in_end, postorder,
                        post_start + left_size, post_end - 1, in_map);

    return root;
  }
};

// @lc code=end
