#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int waysToSplitArray(vector<int> &nums) {
    int ans = 0;
    int n = nums.size();
    long long sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++) {
      sum2 += nums[i];
    }
    for (int i = 0; i < n - 1; i++) {
      sum1 += nums[i];
      sum2 -= nums[i];
      if (sum1 >= sum2) {
        ans += 1;
      }
    }
    cout << sum1 << endl;
    cout << sum2 << endl;
    return ans;
  }
};