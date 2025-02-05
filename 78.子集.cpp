#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  void dfs(vector<int> &path, vector<vector<int>> &ans, int n,
           vector<int> &nums) {
    if (n == nums.size()) {
      ans.push_back(path);
      return;
    }
    // not chosen
    dfs(path, ans, n + 1, nums);
    // chosen
    path.push_back(nums[n]);
    dfs(path, ans, n + 1, nums);
    path.pop_back();
  }
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> ans;
    vector<int> path;
    dfs(path, ans, 0, nums);
    return ans;
  }
};