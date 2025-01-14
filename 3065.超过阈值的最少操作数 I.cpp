#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minOperations(vector<int> &nums, int k) {
    int ans = 0;
    for (auto i : nums) {
      if (i < k) {
        ans++;
      }
    }
    return ans;
  }
};