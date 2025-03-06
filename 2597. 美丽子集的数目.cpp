#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int beautifulSubsets(vector<int> &nums, int k) {
    int ans = -1; // 去掉空集
    unordered_map<int, int> cnt;

    // nums[i] 选或不选
    auto dfs = [&](this auto &&dfs, int i) -> void {
      if (i == nums.size()) {
        ans++;
        return;
      }
      dfs(i + 1); // 不选
      int x = nums[i];
      if (cnt[x - k] == 0 && cnt[x + k] == 0) { // 可以选
        cnt[x]++;                               // 选
        dfs(i + 1);                             // 讨论 nums[i+1] 选或不选
        cnt[x]--;                               // 撤销，恢复现场
      }
    };

    dfs(0);
    return ans;
  }
};