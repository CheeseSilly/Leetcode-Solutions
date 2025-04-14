#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool checkXMatrix(vector<vector<int>> &grid) {
    //[0][0]~[n-1][n-1]
    //[0][n-1]~[n-1][0]
    int f0 = 0;
    int f1 = grid.size() - 1;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid.size(); j++) {
        if (grid[i][i] == 0 || grid[i][grid.size() - i - 1] == 0) {
          return false;
        }
        if (j != i && j != grid.size() - i - 1) {
          if (grid[i][j] != 0) {
            return false;
          }
        }
      }
    }
    return true;
  }
};