#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> ans;
    vector<int> path(n);
    vector<int> visited(n);
    auto dfs = [&](this auto &&dfs, int i) -> void {
      if (i == n) {
        ans.push_back(path);
        return;
      }
      for (int j = 0; j < n; j++) {
        if (visited[j]) {
          continue;
        }
        path[i] = nums[j];
        visited[j] = true;
        dfs(i + 1);
        visited[j] = false;
      }
    };
    dfs(0);
    return ans;
  }
};