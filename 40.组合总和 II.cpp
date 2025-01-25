#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
  void dfs(vector<int> &candidates, vector<int> &visited,
           vector<vector<int>> &ans, int target, int move) {
    if (target == 0) {
      ans.push_back(visited);
      return;
    }
    for (int i = move; i < candidates.size() && candidates[i] <= target; i++) {
      if (i > move && candidates[i - 1] == candidates[i]) {
        continue; //去重剪枝
      }
      visited.push_back(candidates[i]);
      dfs(candidates, visited, ans, target - candidates[i], i + 1);
      visited.pop_back();
    }
  }

public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<vector<int>> ans;
    vector<int> path;
    ranges::sort(candidates);
    dfs(candidates, path, ans, target, 0);
    return ans;
  }
};