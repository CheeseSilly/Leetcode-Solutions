#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> replaceElements(vector<int> &arr) {
    int n = arr.size();
    vector<int> ans(n, -1);
    int cur = 0;
    if (n == 1) {
      return ans;
    }
    // loop [n,1]
    for (int i = n; i >= 1; i--) {
      if (i == n) {
        continue;
      }
      cur = max(cur, arr[i]);
      ans[i - 1] = cur;
    }

    return ans;
  }
};