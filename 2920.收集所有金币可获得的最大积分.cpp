#include <bits/stdc++.h>
#include <format>
#include <ranges>
#include <vector>

using namespace std;

class Solution {
public:
  int maximumPoints(vector<vector<int>> &edges, vector<int> &coins, int k) {
    // 1.ans=coins[i]-k,then if (coins[i]-k<0),ans-=abs(coins[i]-k)
    // 2.ans=floor(coins[i]/2),all j of i :coins[j]=floor(coin[j]/2)
    int ans = 0;
    // enter:dp[0][0]
    // out:dp[i][1]
    // dp[0][0]
    int n = coins.size();
    vector<vector<int>> g(n);
    for (auto &e : edges) {
      int x = e[0], y = e[1];
      g[x].push_back(y);
      g[y].push_back(x);
    }

    array<int, 14> init_val;
    ranges::fill(init_val, -1); // -1 表示没有计算过
    vector memo(n, init_val);
    auto dfs = [&](this auto &&dfs, int i, int j, int fa) {
      int &res = memo[i][j]; // 注意这里是引用
      if (res != -1) {       // 之前计算过
        return res;
      }
      int res1 = (coins[i] >> j) - k;
      int res2 = coins[i] >> (j + 1);
      for (int ch : g[i]) {
        if (ch == fa)
          continue;
        res1 += dfs(ch, j, i); // 不右移
        if (j < 13) {          // j+1 >= 14 相当于 res2 += 0，无需递归
          res2 += dfs(ch, j + 1, i); // 右移
        }
      }
      return res = max(res1, res2); // 记忆化
    };
    return dfs(0, 0, -1);
  }
};