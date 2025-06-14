/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] Remove All Adjacent Duplicates In String
 */

// @lc code=start

#include <algorithm>
#include <stack>
#include <string>
class Solution {
public:
  std::string removeDuplicates(std::string s) {
    std::stack<char> st;
    for (auto str : s) {
      if (st.empty()) {
        st.push(str);
      } else {
        if (st.top() == str) {
          st.pop();
        } else {
          st.push(str);
        }
      }
    }

    // get all elements
    std::string ans;
    while (!st.empty()) {
      ans.push_back(st.top());
      st.pop();
    }
    std::reverse(ans.begin(), ans.end());
    return ans;
  }
};
// @lc code=end
