#include <bits/stdc++.h>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
  int nearestExit(vector<vector<char>> &maze, vector<int> &entrance) {
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int m = maze.size();
    int n = maze[0].size();
    int visited[m][n];
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        visited[i][j] = 0;
      }
    }
    queue<pair<int, int>> q;
    //出口为(0||m-1,0||n-1)
    q.push({entrance[0], entrance[1]});
    visited[entrance[0]][entrance[1]] = 1;
    int step = 0;
    while (!q.empty()) {
      step++;
      int qs = q.size();
      for (int i = 0; i < qs; i++) {
        auto t = q.front();
        q.pop();
        int r1 = t.first, c1 = t.second;
        for (int i = 0; i < 4; i++) {
          int r = r1 + dx[i];
          int c = c1 + dy[i];
          if (r >= 0 && r < m && c >= 0 && c < n && visited[r][c] == 0 &&
              maze[r][c] == '.') {
            if (r == 0 || r == m - 1 || c == 0 || c == n - 1) {
              return step;
            }
            q.push({r, c});
            visited[r][c] = 1;
          }
        }
      }
    }
    return -1;
  }
};