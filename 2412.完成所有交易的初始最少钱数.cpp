#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  long long minimumMoney(vector<vector<int>> &transactions) {
    // max
    long long ans = 0;
    int cashin1 = 0;
    int cashin2 = 0;
    long long cashout = 0;
    for (int i = 0; i < transactions.size(); i++) {
      // if out:
      // money-(allLose-(cost-cash))>=cost
      // money>=allLose+cash,then max(cash)
      if (transactions[i][0] > transactions[i][1]) {
        cashout += transactions[i][0] - transactions[i][1];
        cashin1 = max(cashin1, transactions[i][1]);
        // if in:
        // money-allLose>=cost
        // money>=allLose+cost,thenmax(cost)
      } else {
        cashin2 = max(cashin2, transactions[i][0]);
      }
    }
    return ans = cashout + max(cashin1, cashin2);
  }
};