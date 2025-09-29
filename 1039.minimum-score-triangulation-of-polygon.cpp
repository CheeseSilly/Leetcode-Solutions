/*
 * @lc app=leetcode.cn id=1039 lang=cpp
 *
 * [1039] Minimum Score Triangulation of Polygon
 */

// @lc code=start
class Solution {
public:
  int minScoreTriangulation(vector<int> &values) {
    int n = values.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    /**min: from i to j
     * edge: dfs(i,i+1)
     * entry: dfs(0,n-1)
     */
    auto dfs = [&](this auto &&dfs, int i, int j) {
      if (i + 1 == j) {
        return 0;
      }
      int &res = dp[i][j];
      if (res != -1) {
        return res;
      }
      res = INT_MAX;
      for (int k = i + 1; k < j; k++) {
        res =
            min(res, dfs(i, k) + dfs(k, j) + values[i] * values[k] * values[j]);
      }
      return res;
    };
    return dfs(0, n - 1);
  }
};
// @lc code=end
