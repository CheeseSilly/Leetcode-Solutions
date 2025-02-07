#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> ans;
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> visited(m, vector<int>(n, 0));
    vector<vector<int>> dic = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int r = 0, c = 0, idx = 0;
    for (int i = 0; i < m * n; i++) {
      ans.push_back(matrix[r][c]);
      visited[r][c] = true;
      int x = r + dic[idx][0];
      int y = c + dic[idx][1];
      if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y]) {
        idx = (idx + 1) % 4;
      }
      r = r + dic[idx][0];
      c = c + dic[idx][1];
    }
    return ans;
  }
};