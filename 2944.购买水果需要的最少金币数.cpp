#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int dfs(int i, int n, vector<int> &dp, vector<int> &prices) {
    if (2 * i >= n) {
      return prices[i - 1];
    }
    int &res = dp[i];
    if (res) {
      return res;
    }
    res = INT_MAX;
    for (int j = i + 1; j <= i * 2 + 1; j++) {
      // free to get
      res = min(res, dfs(j, n, dp, prices));
    }
    // buy to get
    res += prices[i - 1];
    return res;
  }
  int minimumCoins(vector<int> &prices) {
    int cost = 0;
    int n = prices.size();
    // i为第i个水果
    // 选:dp[i][0]=prices[i]
    //免费:dp[i][1]=min(dp[i/2][0]...dp[i-1][0]);                 [i+1,i+i]
    vector<int> dp(n + 1, 0);
    return dfs(1, n, dp, prices);
  }
};

// class Solution {
// public:
//     int minimumCoins(vector<int>& prices) {
//         int n = prices.size();
//         vector<int> memo((n + 1) / 2);
//         auto dfs = [&](this auto&& dfs, int i) -> int {
//             if (i * 2 >= n) {
//                 return prices[i - 1]; // i 从 1 开始
//             }
//             int& res = memo[i]; // 注意这里是引用
//             if (res) { // 之前算过
//                 return res;
//             }
//             res = INT_MAX;
//             for (int j = i + 1; j <= i * 2 + 1; j++) {
//                 res = min(res, dfs(j));
//             }
//             res += prices[i - 1];
//             return res;
//         };
//         return dfs(1);
//     }
// };