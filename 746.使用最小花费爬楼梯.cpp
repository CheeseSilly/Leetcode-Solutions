#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minCostClimbingStairs(vector<int> &cost) {
    int top = cost.size();
    vector<int> dp(top + 1);
    int ans = 0;
    // first=0||1
    dp[0] = cost[0];
    dp[1] = cost[1];
    // entry:dp[top-2] step 2;
    // dp[top-1] step 1;
    // dp[i]=min(cost[i-2],cost[i-1])
    for (int i = 2; i <= top; i++) {
      if (i != top)
        dp[i] = cost[i];
      dp[i] += min(dp[i - 1], dp[i - 2]);
    }
    ans = dp[top];
    return ans;
  }
};