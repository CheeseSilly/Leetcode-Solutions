#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maxValueOfCoins(vector<vector<int>> &piles, int k) {
    // sum;
    // max[i]=max(f(i-1,j-w))+v;
    // k is num of coins chosen
    int ans = 0;
    int n = size(piles);
    vector memo(n, vector<int>(k + 1));
    auto dfs = [&](this auto &&dfs, int i, int j) -> int {
      if (i < 0) {
        return 0;
      }
      int &res = memo[i][j]; // 注意这里是引用
      if (res) {             // 之前计算过
        return res;
      }
      // 不选这一组中的任何物品
      res = dfs(i - 1, j);
      // 枚举选哪个
      int v = 0;
      for (int w = 0; w < min(j, (int)piles[i].size()); w++) {
        v += piles[i][w];
        // w 从 0 开始，物品体积为 w+1
        res = max(res, dfs(i - 1, j - w - 1) + v);
      }
      return res;
    };
    return dfs(n - 1, k);
  }
};
