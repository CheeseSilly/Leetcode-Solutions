/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 */

// @lc code=start
// Definition for a binary tree node.
#include <stack>
/* struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
}; */

#include <vector>
class Solution {
public:
  std::vector<int> preorderTraversal(TreeNode *root) {
    std::vector<int> ans;
    std::stack<TreeNode *> st;
    if (root) {
      st.push(root);
    }
    while (!st.empty()) {
      auto node = st.top();
      if (node) {
        st.pop();
        if (node->right)
          st.push(node->right);
        if (node->left)
          st.push(node->left);
        st.push(node);
        st.push(nullptr);

      } else {
        st.pop(); // remove nullptr
        node = st.top();
        st.pop();
        ans.push_back(node->val);
      }
    }
    return ans;
  }
};
// @lc code=end
