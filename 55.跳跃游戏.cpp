#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool canJump(vector<int> &nums) {
    int n = nums.size();

    // if reach n-1
    // end:i+nums[j]=n-1
    int nxt = 0;
    int cur = 0;
    for (int i = 0; i < n - 1; i++) {
      nxt = max(nxt, i + nums[i]);
      if (i == cur) {
        cur = nxt;
      }
    }
    return cur >= n - 1 ? true : false;
  }
};