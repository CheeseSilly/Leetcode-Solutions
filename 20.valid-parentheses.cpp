/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */
#include <map>
#include <stack>
#include <string>
#include <vector>
// @lc code=start
class Solution {
public:
  bool isValid(std::string s) {
    std::stack<char> st;
    std::map<char, char> strMap;
    strMap['('] = ')';
    strMap['['] = ']';
    strMap['{'] = '}';

    for (auto str : s) {
      if (st.empty()) {
        if (str == ')' || str == ']' || str == '}') {
          return false;
        } else {
          st.push(str);
          continue;
        }
      }
      auto top = st.top();
      if (strMap[top] == str) {
        st.pop();
      } else if (str == ')' || str == ']' || str == '}') {
        return false;
      } else {
        st.push(str);
      }
    }
    return st.empty();
  }
};
// @lc code=end
