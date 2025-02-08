#include <bits/stdc++.h>
#include <utility>

using namespace std;

class Solution1 {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    vector<vector<int>> moves = {{0, 1}, {1, 0}};
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> visited(m, vector<int>(n, -1));
    int ans = 0;
    auto dfs = [&](this auto &&dfs, int i, int j) -> int {
      if (i < 0 || i >= m || j < 0 || j >= n || obstacleGrid[i][j]) {
        return 0;
      }
      if (i == m - 1 && j == n - 1) {
        return 1;
      }
      int &res = visited[i][j];
      if (res != -1) {
        return res;
      }
      return res = dfs(i + 1, j) + dfs(i, j + 1);
    };
    return dfs(0, 0);
  }
};

class Solution2 {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m + 1, vector(n + 1, 0));
    // dp[1][1]=1;
    // dp[i+1][j+1]=dp[i+1][j]+dp[i][j+1]
    dp[1][0] = 1;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (obstacleGrid[i][j] == 0)
          dp[i + 1][j + 1] = dp[i + 1][j] + dp[i][j + 1];
      }
    }
    return dp[m][n];
  }
};