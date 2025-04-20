#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> ans;
    vector<int> path;

    auto dfs = [&](this auto &&dfs, int i) -> void {
      if (i == n) {
        ans.push_back(path);
        return;
      }

      // 选 x
      int x = nums[i];
      path.push_back(x);
      dfs(i + 1);
      path.pop_back();  // 恢复现场

      // 不选 x，跳过所有等于 x 的数
      // 如果不跳过这些数，会导致「选 x 不选 x'」和「不选 x 选
      // x'」这两种情况都会加到 ans 中，这就重复了
      i++;
      while (i < n && nums[i] == x) {
        i++;
      }
      dfs(i);
    };

    dfs(0);
    return ans;
  }
};
