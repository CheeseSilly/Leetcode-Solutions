#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  long long beautifulSubarrays(vector<int> &nums) {
    long long ans = 0;
    int s = 0;
    unordered_map<int, int> cnt{{0, 1}};
    for (int x : nums) {
      s ^= x;
      ans += cnt[s]++;
    }
    return ans;
  }
};