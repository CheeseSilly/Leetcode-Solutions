#include <bits/stdc++.h>
#include <climits>

using namespace std;

class Solution {
public:
  int maxCount(int m, int n, vector<vector<int>> &ops) {
    int ans = 0;
    int min0 = INT_MAX;
    int min1 = INT_MAX;
    if (ops.size() == 0) {
      return m * n;
    }
    for (auto i : ops) {
      int x = i[0];
      int y = i[1];
      min0 = ((min0 > x) ? x : min0);
      min1 = ((min1 > y) ? y : min1);
    }
    return min0 * min1;
  }
};