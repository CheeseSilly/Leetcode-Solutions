#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maxCoins(vector<int> &piles) {
    int n = piles.size();
    int num = 0;
    sort(piles.begin(), piles.end());
    int ans = 0;
    // 1,2,3,4,5,6,7,8,9
    for (int i = n - 2; i >= 1; i = i - 2) {
      num++;
      ans += piles[i];
      if (num == n / 3) {
        break;
      }
    }
    return ans;
  }
};