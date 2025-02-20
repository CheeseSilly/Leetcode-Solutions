#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
    int m = floor.size();
    vector memo(numCarpets + 1, vector<int>(m, -1)); // -1 表示没有计算过
    auto dfs = [&](this auto &&dfs, int i, int j) -> int {
      if (j < carpetLen * i) { // 剩余砖块可以全部覆盖
        return 0;
      }
      int &res = memo[i][j]; // 注意这里是引用
      if (res != -1) {       // 之前计算过
        return res;
      }
      if (i == 0) {
        return res = dfs(i, j - 1) + (floor[j] - '0');
      }
      return res = min(dfs(i, j - 1) + (floor[j] - '0'),
                       dfs(i - 1, j - carpetLen));
    };
    return dfs(numCarpets, m - 1);
  }
};