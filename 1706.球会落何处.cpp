#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> findBall(vector<vector<int>> &grid) {
    vector<vector<int>> dic = {{1, -1}, {1, 1}}; // left:r+1,c-1; right:r+1,c+1
    int m = grid.size();
    int n = grid[0].size();
    vector<int> ans;

    auto dfs = [&](this auto &&dfs, int r, int c) -> int {
      if (c == 0 && grid[r][c] == -1) {
        return -1;
      }
      if (c == n - 1 && grid[r][c] == 1) {
        return -1;
      }
      if (grid[r][c] != grid[r][c + grid[r][c]])
        return -1;
      if (r == m - 1) {
        return c + grid[r][c];
      }
      return dfs(r + 1, c + grid[r][c]);
    };

    for (int i = 0; i < n; i++) {
      ans.push_back(dfs(0, i));
    }
    return ans;
  }
};