#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maxDistance(vector<vector<int>> &arrays) {
    int ans = 0;
    int mn = INT_MAX / 2, mx = INT_MIN / 2; // 防止减法溢出
    for (auto &a : arrays) {
      ans = max({ans, a.back() - mn, mx - a[0]});
      mn = min(mn, a[0]);
      mx = max(mx, a.back());
    }
    return ans;
  }
};