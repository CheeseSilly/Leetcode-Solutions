/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

#include <vector>
class Solution {
public:
  std::vector<std::vector<int>> levelOrder(Node *root) {
    std::vector<std::vector<int>> ans;
    auto bfs = [&](this auto &&bfs, int depth, Node *cur) {
      if (!cur) {
        return;
      }
      if (ans.size() == depth) {
        ans.push_back(std::vector<int>());
      }
      ans[depth].push_back(cur->val);
      for (auto child : cur->children) {
        bfs(depth + 1, child);
      }
    };

    bfs(0, root);
    return ans;
  }
};
// @lc code=end
