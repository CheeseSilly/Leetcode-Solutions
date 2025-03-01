#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minCut(string s) {
    int n = s.size();
    vector pal_memo(n, vector<int>(n, -1)); // -1 表示没有计算过
    auto is_palindrome = [&](this auto &&is_palindrome, int l, int r) -> bool {
      if (l >= r) {
        return true;
      }
      int &res = pal_memo[l][r]; // 注意这里是引用
      if (res != -1) {           // 之前计算过
        return res;
      }
      return res = s[l] == s[r] && is_palindrome(l + 1, r - 1);
    };

    vector<int> dfs_memo(n, INT_MAX); // INT_MAX 表示没有计算过
    auto dfs = [&](this auto &&dfs, int r) -> int {
      if (is_palindrome(0, r)) { // 已是回文串，无需分割
        return 0;
      }
      int &res = dfs_memo[r]; // 注意这里是引用
      if (res != INT_MAX) {   // 之前计算过
        return res;
      }
      for (int l = 1; l <= r; l++) { // 枚举分割位置
        if (is_palindrome(l, r)) {
          res = min(res, dfs(l - 1) + 1); // 在 l-1 和 l 之间切一刀
        }
      }
      return res;
    };
    return dfs(n - 1);
  }
};