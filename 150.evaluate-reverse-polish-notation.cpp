/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
#include <algorithm>
#include <functional>
#include <map>
#include <stack>
#include <string>
#include <vector>

class Solution {
public:
  int evalRPN(std::vector<std::string> &tokens) {
    for (auto token : tokens) {
      if (std::find(operators.begin(), operators.end(), token) ==
          operators.end()) {
        st.push(std::stoi(token));
      } else {
        if (cals.contains(token)) {
          cals[token]();
        }
      }
    }
    return st.top();
  }

private:
  std::stack<int> st;
  std::vector<std::string> operators = {"+", "-", "*", "/"};
  // map for calculating
  std::map<std::string, std::function<void()>> cals = {
      {"+",
       [&] {
         auto tmp2 = st.top();
         st.pop();
         auto tmp1 = st.top();
         st.pop();
         st.push((tmp1 + tmp2));
       }},
      {"-",
       [&] {
         auto tmp2 = st.top();
         st.pop();
         auto tmp1 = st.top();
         st.pop();
         st.push((tmp1 - tmp2));
       }},
      {"*",
       [&] {
         auto tmp2 = st.top();
         st.pop();
         auto tmp1 = st.top();
         st.pop();
         st.push((tmp1 * tmp2));
       }},
      {"/", [&] {
         auto tmp2 = st.top();
         st.pop();
         auto tmp1 = st.top();
         st.pop();
         st.push((tmp1 / tmp2));
       }}};
};
// @lc code=end
