#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool isPalindrom(string &s, int left, int right) {
    while (left < right) {
      if (s[left++] != s[right--]) {
        return false;
      }
    }
    return true;
  }
  vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> path;
    int n = s.length();
    auto dfs = [&](this auto &&dfs, int i, int start) {
      if (i == n) {
        ans.emplace_back(path);
        return;
      }
      if (i < n - 1) {
        dfs(i + 1, start);
      }
      if (isPalindrom(s, start, i)) {
        path.push_back(s.substr(start, i - start + 1));
        dfs(i + 1, start + 1);
        path.pop_back();
      }
    };
    dfs(0, 0);
    return ans;
  }
};