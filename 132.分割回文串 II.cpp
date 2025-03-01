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
  int minCut(string s) {
    int num = s.length();
    int ans = 0;
    string path;
    auto dfs = [&](this auto &&dfs, int i, int l) -> void {
      if (l == num) {
        return;
      }

      // not cut
      if (i < n - 1)
        dfs(i + 1, l);

      // cut it
      if (isPalindrom(s, l, i)) {
        ans++;
        dfs(i + 1, l + 1);
      }
    };
    dfs(0, 0);
    return ans;
  }
};