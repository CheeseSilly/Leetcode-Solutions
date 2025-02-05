#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    // sort first makes loop more easily!
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> ans;
    vector<int> path;
    vector<int> visited(n);
    auto dfs = [&](this auto &&dfs, int i) -> void {
      if (i == n) {
        ans.push_back(path);
        return;
      }
      for (int j = 0; j < n; j++) {
        // 1,2,3,2
        // how to deal with 2 & 2
        if (visited[j] || j > 0 && nums[j] == nums[j - 1] && !visited[j - 1]) {
          continue;
        }
        path.push_back(nums[j]);
        visited[j] = true;
        dfs(i + 1);
        path.pop_back();
        visited[j] = false;
      }
    };
    dfs(0);
    return ans;
  }
};