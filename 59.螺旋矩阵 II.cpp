#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    // 0,1,2  row=0,col++(until col=n-1)  (0,2)
    // 0,1,2 col=n-1,row++(until row=n-1)
    // 2,1,0 row=n-1,col--
    // row--
    //.......

    // entry=(0,0)
    // end=path.size()==pow(n,2);?

    vector<vector<int>> ans(n, vector<int>(n));
    vector<int> path;
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int r = 0, c = 0, flag = 0;
    for (int i = 1; i <= n * n; i++) {
      ans[r][c] = i;
      int x = r + dir[flag][0];
      int y = c + dir[flag][1];
      if (x < 0 || x >= n || y < 0 || y >= n || ans[x][y]) {
        flag = (flag + 1) % 4;
      }
      r = r + dir[flag][0];
      c = c + dir[flag][1];
    }
    return ans;
  }
};