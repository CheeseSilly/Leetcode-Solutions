#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int jump(vector<int> &nums) {
    int n = nums.size();
    // min num of jump
    int ans = 0;

    //范围 0~nums[i+nums[i]]

    // des:i+j==n-1
    int nxt = 0;
    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
      nxt = max(nxt, i + nums[i]);
      if (cnt == i) {
        cnt = nxt;
        ans++;
      }
    }
    return ans;
  }
};